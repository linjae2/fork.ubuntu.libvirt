/*
 * qemu_tpm.c: QEMU TPM support
 *
 * Copyright (C) 2018 IBM Corporation
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library.  If not, see
 * <http://www.gnu.org/licenses/>.
 */

#include <config.h>

#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>

#include "qemu_extdevice.h"
#include "qemu_security.h"

#include "conf/domain_conf.h"
#include "vircommand.h"
#include "viridentity.h"
#include "virlog.h"
#include "viruuid.h"
#include "virfile.h"
#include "virpidfile.h"
#include "configmake.h"
#include "qemu_tpm.h"
#include "virtpm.h"
#include "virsecret.h"
#include "virtime.h"

#define VIR_FROM_THIS VIR_FROM_NONE

VIR_LOG_INIT("qemu.tpm");

/**
 * qemuTPMEmulatorStorageBuildPath:
 * @swtpmStorageDir: directory for swtpm persistent state
 * @uuidstr: UUID of the VM
 * @tpmversion: version of the TPM
 *
 * Generate the swtpm's storage path.
 */
static char *
qemuTPMEmulatorStorageBuildPath(const char *swtpmStorageDir,
                                const char *uuidstr,
                                virDomainTPMVersion tpmversion)
{
    char *path = NULL;
    const char *dir = "";

    switch (tpmversion) {
    case VIR_DOMAIN_TPM_VERSION_1_2:
        dir = "tpm1.2";
        break;
    case VIR_DOMAIN_TPM_VERSION_2_0:
        dir = "tpm2";
        break;
    case VIR_DOMAIN_TPM_VERSION_DEFAULT:
    case VIR_DOMAIN_TPM_VERSION_LAST:
        return NULL;
    }

    path = g_strdup_printf("%s/%s/%s", swtpmStorageDir, uuidstr, dir);
    return path;
}


/**
 * qemuTPMEmulatorLogBuildPath:
 * @logDir: directory for swtpm log files
 * @vmname: name of the VM
 *
 * Generate the swtpm's log path.
 */
static char*
qemuTPMEmulatorLogBuildPath(const char *logDir,
                            const char *vmname)
{
    return g_strdup_printf("%s/%s-swtpm.log", logDir, vmname);
}


/**
 * qemuTPMEmulatorSocketBuildPath:
 * @swtpmStateDir: directory for swtpm runtime state
 * @shortName: short and unique name of the domain
 *
 * Generate the swtpm's Unix socket path.
 */
static char *
qemuTPMEmulatorSocketBuildPath(const char *swtpmStateDir,
                               const char *shortName)
{
    return g_strdup_printf("%s/%s-swtpm.sock", swtpmStateDir, shortName);
}


/**
 * qemuTPMEmulatorPidFileBuildPath:
 * @swtpmStateDir: directory for swtpm runtime state
 * @shortName: short and unique name of the domain
 *
 * Generate the swtpm's pidfile path.
 */
static char *
qemuTPMEmulatorPidFileBuildPath(const char *swtpmStateDir,
                                const char *shortName)
{
    g_autofree char *devicename = NULL;

    devicename = g_strdup_printf("%s-swtpm", shortName);

    return virPidFileBuildPath(swtpmStateDir, devicename);
}


/*
 * qemuTPMEmulatorGetPid
 *
 * @swtpmStateDir: the directory where swtpm writes the pidfile into
 * @shortName: short name of the domain
 * @pid: pointer to pid
 *
 * Return -1 upon error, or zero on successful reading of the pidfile.
 * If the PID was not still alive, zero will be returned, and @pid will be
 * set to -1;
 */
static int
qemuTPMEmulatorGetPid(const char *swtpmStateDir,
                      const char *shortName,
                      pid_t *pid)
{
    g_autofree char *pidfile = qemuTPMEmulatorPidFileBuildPath(swtpmStateDir,
                                                               shortName);
    if (!pidfile)
        return -1;

    if (virPidFileReadPathIfLocked(pidfile, pid) < 0)
        return -1;

    return 0;
}


/**
 * qemuTPMEmulatorCreateStorage:
 * @tpm: TPM definition for an emulator type
 * @created: a pointer to a bool that will be set to true if the
 *           storage was created because it did not exist yet
 * @swtpm_user: The uid that needs to be able to access the directory
 * @swtpm_group: The gid that needs to be able to access the directory
 *
 * Unless the storage path for the swtpm for the given VM
 * already exists, create it and make it accessible for the given userid.
 * Adapt ownership of the directory and all swtpm's state files there.
 */
static int
qemuTPMEmulatorCreateStorage(virDomainTPMDef *tpm,
                             bool *created,
                             uid_t swtpm_user,
                             gid_t swtpm_group)
{
    const char *source_path = tpm->data.emulator.source_path;
    g_autofree char *swtpmStorageDir = g_path_get_dirname(source_path);

    /* allow others to cd into this dir */
    if (g_mkdir_with_parents(swtpmStorageDir, 0711) < 0) {
        virReportSystemError(errno,
                             _("Could not create TPM directory %1$s"),
                             swtpmStorageDir);
        return -1;
    }

    *created = false;

    if (!virFileExists(source_path) ||
        virDirIsEmpty(source_path, true) > 0)
        *created = true;

    if (virDirCreate(source_path, 0700, swtpm_user, swtpm_group,
                     VIR_DIR_CREATE_ALLOW_EXIST) < 0) {
        virReportError(VIR_ERR_INTERNAL_ERROR,
                       _("Could not create directory %1$s as %2$u:%3$d"),
                       source_path, swtpm_user, swtpm_group);
        return -1;
    }

    if (virFileChownFiles(source_path, swtpm_user, swtpm_group) < 0)
        return -1;

    return 0;
}


/**
 * qemuTPMEmulatorDeleteStorage:
 * @tpm: TPM definition
 *
 * Delete all persistent storage associated with the swtpm.
 */
static void
qemuTPMEmulatorDeleteStorage(virDomainTPMDef *tpm)
{
    g_autofree char *path = g_path_get_dirname(tpm->data.emulator.source_path);

    ignore_value(virFileDeleteTree(path));
}


/*
 * qemuTPMSetupEncryption
 *
 * @secretuuid: The UUID with the secret holding passphrase
 * @cmd: the virCommand to transfer the secret to
 * @fd: returned read-end of the pipe
 *
 * Sets @fd to a file descriptor representing the read-end of a
 * pipe. The passphrase can be read from this pipe.
 *
 * This function reads the passphrase and writes it into the
 * write-end of a pipe so that the read-end of the pipe can be
 * passed to the emulator for reading the passphrase from.
 *
 * Note that the returned @fd is owned by @cmd and thus should
 * only be used to append an argument onto emulator cmdline.
 *
 * Returns: 0 on success,
 *         -1 otherwise (with proper error reported).
 */
static int
qemuTPMSetupEncryption(const unsigned char *secretuuid,
                       virCommand *cmd,
                       int *fd)
{
    g_autoptr(virConnect) conn = NULL;
    g_autofree uint8_t *secret = NULL;
    size_t secret_len;
    virSecretLookupTypeDef seclookupdef = {
         .type = VIR_SECRET_LOOKUP_TYPE_UUID,
    };
    VIR_IDENTITY_AUTORESTORE virIdentity *oldident = virIdentityElevateCurrent();

    if (!oldident)
        return -1;

    conn = virGetConnectSecret();
    if (!conn)
        return -1;

    memcpy(seclookupdef.u.uuid, secretuuid, sizeof(seclookupdef.u.uuid));
    if (virSecretGetSecretString(conn, &seclookupdef,
                                 VIR_SECRET_USAGE_TYPE_VTPM,
                                 &secret, &secret_len) < 0)
        return -1;

    *fd = virCommandSetSendBuffer(cmd, &secret, secret_len);
    return 0;
}


/*
 * qemuTPMCreateConfigFiles: run swtpm_setup --create-config-files skip-if-exist
 */
static int
qemuTPMCreateConfigFiles(const char *swtpm_setup)
{
    g_autoptr(virCommand) cmd = NULL;
    g_autofree char *errbuf = NULL;
    int exitstatus;

    if (!virTPMSwtpmSetupCapsGet(
            VIR_TPM_SWTPM_SETUP_FEATURE_CMDARG_CREATE_CONFIG_FILES))
        return 0;

    cmd = virCommandNew(swtpm_setup);

    virCommandAddArgList(cmd, "--create-config-files", "skip-if-exist", NULL);
    virCommandClearCaps(cmd);
    virCommandSetErrorBuffer(cmd, &errbuf);

    if (virCommandRun(cmd, &exitstatus) < 0)
        return -1;
    if (exitstatus != 0) {
        virReportError(VIR_ERR_INTERNAL_ERROR,
                       _("Could not run '%1$s' to create config files. exitstatus: %2$d;\nError: %3$s"),
                          swtpm_setup, exitstatus, errbuf);
        return -1;
    }

    return 0;
}


/*
 * Add encryption parameters to swtpm_setup command line.
 *
 * @cmd: virCommand to add options to
 * @swtpm_setup: swtpm_setup tool path
 * @secretuuid: The secret's uuid; may be NULL
 */
static int
qemuTPMVirCommandAddEncryption(virCommand *cmd,
                               const char *swtpm_setup,
                               const unsigned char *secretuuid)
{
    int pwdfile_fd;

    if (!secretuuid)
        return 0;

    if (!virTPMSwtpmSetupCapsGet(VIR_TPM_SWTPM_SETUP_FEATURE_CMDARG_PWDFILE_FD)) {
        virReportError(VIR_ERR_ARGUMENT_UNSUPPORTED,
                       _("%1$s does not support passing a passphrase using a file descriptor"),
                       swtpm_setup);
        return -1;
    }

    if (qemuTPMSetupEncryption(secretuuid, cmd, &pwdfile_fd) < 0)
        return -1;

    virCommandAddArg(cmd, "--pwdfile-fd");
    virCommandAddArgFormat(cmd, "%d", pwdfile_fd);
    virCommandAddArgList(cmd, "--cipher", "aes-256-cbc", NULL);
    virCommandPassFD(cmd, pwdfile_fd, VIR_COMMAND_PASS_FD_CLOSE_PARENT);

    return 0;
}


static char *
qemuTPMGetSwtpmSetupStateArg(const virDomainTPMSourceType source_type,
                             const char *source_path)
{
    const char *lock = ",lock";

    if (!virTPMSwtpmSetupCapsGet(VIR_TPM_SWTPM_SETUP_FEATURE_TPMSTATE_OPT_LOCK)) {
        VIR_WARN("This swtpm version doesn't support explicit locking");
        lock = "";
    }

    switch (source_type) {
    case VIR_DOMAIN_TPM_SOURCE_TYPE_FILE:
        /* the file:// prefix is supported since swtpm_setup 0.7.0 */
        /* assume the capability check for swtpm is redundant. */
        return g_strdup_printf("file://%s%s", source_path, lock);
    case VIR_DOMAIN_TPM_SOURCE_TYPE_DIR:
    case VIR_DOMAIN_TPM_SOURCE_TYPE_DEFAULT:
    case VIR_DOMAIN_TPM_SOURCE_TYPE_LAST:
    default:
        return g_strdup_printf("%s%s", source_path, lock);
    }
}


/*
 * Add a (optional) profile to the swtpm_setup command line.
 *
 * @cmd: virCommand to add options to
 * @emulator: emulator parameters
 *
 * Returns 0 on success, -1 on failure.
 */
static int
qemuTPMVirCommandAddProfile(virCommand *cmd,
                            const virDomainTPMEmulatorDef *emulator)
{
    if (!emulator->profile.source)
        return 0;

    if (!virTPMSwtpmSetupCapsGet(VIR_TPM_SWTPM_SETUP_FEATURE_CMDARG_PROFILE)) {
        virReportError(VIR_ERR_ARGUMENT_UNSUPPORTED, "%s",
                       _("swtpm_setup has no support for profiles"));
        return -1;
    }

    virCommandAddArgList(cmd,
                         "--profile-name", emulator->profile.source,
                         NULL);

    if (emulator->profile.removeDisabled) {
        virCommandAddArgList(cmd,
                             "--profile-remove-disable",
                             virDomainTPMProfileRemoveDisabledTypeToString(emulator->profile.removeDisabled),
                             NULL);
    }
    return 0;
}


/*
 * qemuTPMEmulatorRunSetup
 *
 * @emulator: emulator parameters
 * @vmname: the name of the VM
 * @vmuuid: the UUID of the VM
 * @privileged: whether we are running in privileged mode
 * @cfg: virQEMUDriverConfig
 * @secretuuid: UUID describing virStorageEncryption holding secret
 * @incomingMigration: whether we have an incoming migration
 *
 * Setup the external swtpm by creating endorsement key and
 * certificates for it.
 */
static int
qemuTPMEmulatorRunSetup(const virDomainTPMEmulatorDef *emulator,
                        const char *vmname,
                        const unsigned char *vmuuid,
                        bool privileged,
                        const virQEMUDriverConfig *cfg,
                        const unsigned char *secretuuid,
                        bool incomingMigration)
{
    g_autoptr(virCommand) cmd = NULL;
    int exitstatus;
    char uuid[VIR_UUID_STRING_BUFLEN];
    g_autofree char *vmid = NULL;
    g_autofree char *swtpm_setup = virTPMGetSwtpmSetup();
    g_autofree char *tpm_state = qemuTPMGetSwtpmSetupStateArg(emulator->source_type,
                                                              emulator->source_path);

    if (!swtpm_setup)
        return -1;

    if (!privileged && emulator->version == VIR_DOMAIN_TPM_VERSION_1_2 &&
        !virTPMSwtpmSetupCapsGet(VIR_TPM_SWTPM_SETUP_FEATURE_TPM12_NOT_NEED_ROOT)) {
        return virFileWriteStr(emulator->logfile,
                               _("Did not create EK and certificates since this requires privileged mode for a TPM 1.2\n"), 0600);
    }

    if (!privileged && qemuTPMCreateConfigFiles(swtpm_setup) < 0)
        return -1;

    cmd = virCommandNew(swtpm_setup);

    virUUIDFormat(vmuuid, uuid);
    vmid = g_strdup_printf("%s:%s", vmname, uuid);

    virCommandSetUID(cmd, cfg->swtpm_user); /* should be uid of 'tss' or 'root' */
    virCommandSetGID(cmd, cfg->swtpm_group);

    switch (emulator->version) {
    case VIR_DOMAIN_TPM_VERSION_1_2:
        break;
    case VIR_DOMAIN_TPM_VERSION_2_0:
        virCommandAddArgList(cmd, "--tpm2", NULL);
        break;
    case VIR_DOMAIN_TPM_VERSION_DEFAULT:
    case VIR_DOMAIN_TPM_VERSION_LAST:
        break;
    }

    if (qemuTPMVirCommandAddEncryption(cmd, swtpm_setup, secretuuid) < 0)
        return -1;

    if (!incomingMigration) {
        virCommandAddArgList(cmd,
                             "--tpm-state", tpm_state,
                             "--vmid", vmid,
                             "--logfile", emulator->logfile,
                             "--createek",
                             "--create-ek-cert",
                             "--create-platform-cert",
                             "--lock-nvram",
                             "--not-overwrite",
                             NULL);
        if (qemuTPMVirCommandAddProfile(cmd, emulator) < 0)
            return -1;
    } else {
        virCommandAddArgList(cmd,
                             "--tpm-state", tpm_state,
                             "--logfile", emulator->logfile,
                             "--overwrite",
                             NULL);
    }

    virCommandClearCaps(cmd);

    if (virCommandRun(cmd, &exitstatus) < 0 || exitstatus != 0) {
        virReportError(VIR_ERR_INTERNAL_ERROR,
                       _("Could not run '%1$s'. exitstatus: %2$d; Check error log '%3$s' for details."),
                          swtpm_setup, exitstatus, emulator->logfile);
        return -1;
    }

    return 0;
}


static char *
qemuTPMPcrBankBitmapToStr(virBitmap *activePcrBanks)
{
    g_auto(virBuffer) buf = VIR_BUFFER_INITIALIZER;
    ssize_t bank = -1;

    if (!activePcrBanks)
        return NULL;

    while ((bank = virBitmapNextSetBit(activePcrBanks, bank)) > -1)
        virBufferAsprintf(&buf, "%s,", virDomainTPMPcrBankTypeToString(bank));

    virBufferTrim(&buf, ",");

    return virBufferContentAndReset(&buf);
}


/*
 * qemuTPMEmulatorReconfigure
 *
 * @emulator: emulator parameters
 * @cfg: virQEMUDriverConfig
 * @secretuuid: The secret's UUID needed for state encryption
 *
 * Reconfigure the active PCR banks of a TPM 2.
 */
static int
qemuTPMEmulatorReconfigure(const virDomainTPMEmulatorDef *emulator,
                           const virQEMUDriverConfig *cfg,
                           const unsigned char *secretuuid)
{
    g_autoptr(virCommand) cmd = NULL;
    int exitstatus;
    g_autofree char *activePcrBanksStr = NULL;
    g_autofree char *swtpm_setup = virTPMGetSwtpmSetup();
    g_autofree char *tpm_state = qemuTPMGetSwtpmSetupStateArg(emulator->source_type,
                                                              emulator->source_path);

    if (!swtpm_setup)
        return -1;

    if (emulator->version != VIR_DOMAIN_TPM_VERSION_2_0 ||
        (activePcrBanksStr = qemuTPMPcrBankBitmapToStr(emulator->activePcrBanks)) == NULL ||
        !virTPMSwtpmSetupCapsGet(VIR_TPM_SWTPM_SETUP_FEATURE_CMDARG_RECONFIGURE_PCR_BANKS))
        return 0;

    cmd = virCommandNew(swtpm_setup);

    virCommandSetUID(cmd, cfg->swtpm_user); /* should be uid of 'tss' or 'root' */
    virCommandSetGID(cmd, cfg->swtpm_group);

    virCommandAddArgList(cmd, "--tpm2", NULL);

    if (qemuTPMVirCommandAddEncryption(cmd, swtpm_setup, secretuuid) < 0)
        return -1;

    virCommandAddArgList(cmd,
                         "--tpm-state", tpm_state,
                         "--logfile", emulator->logfile,
                         "--pcr-banks", activePcrBanksStr,
                         "--reconfigure",
                         NULL);

    virCommandClearCaps(cmd);

    if (virCommandRun(cmd, &exitstatus) < 0 || exitstatus != 0) {
        virReportError(VIR_ERR_INTERNAL_ERROR,
                       _("Could not run '%1$s --reconfigure'. exitstatus: %2$d; Check error log '%3$s' for details."),
                          swtpm_setup, exitstatus, emulator->logfile);
        return -1;
    }

    return 0;
}

static int
qemuTPMVirCommandSwtpmAddEncryption(virCommand *cmd,
                                    const virDomainTPMEmulatorDef *emulator,
                                    const char *swtpm)
{
    int pwdfile_fd = -1;
    int migpwdfile_fd = -1;

    if (!emulator->hassecretuuid)
        return 0;

    if (!virTPMSwtpmCapsGet(VIR_TPM_SWTPM_FEATURE_CMDARG_PWD_FD)) {
        virReportError(VIR_ERR_ARGUMENT_UNSUPPORTED,
                       _("%1$s does not support passing passphrase via file descriptor"),
                       swtpm);
        return -1;
    }

    if (qemuTPMSetupEncryption(emulator->secretuuid,
                               cmd, &pwdfile_fd) < 0)
        return -1;

    if (qemuTPMSetupEncryption(emulator->secretuuid,
                               cmd, &migpwdfile_fd) < 0)
        return -1;

    virCommandAddArg(cmd, "--key");
    virCommandAddArgFormat(cmd, "pwdfd=%d,mode=aes-256-cbc", pwdfile_fd);

    virCommandAddArg(cmd, "--migration-key");
    virCommandAddArgFormat(cmd, "pwdfd=%d,mode=aes-256-cbc", migpwdfile_fd);
    return 0;
}

static void
qemuTPMVirCommandSwtpmAddTPMState(virCommand *cmd,
                                  const virDomainTPMEmulatorDef *emulator)
{
    virCommandAddArg(cmd, "--tpmstate");
    switch (emulator->source_type) {
    case VIR_DOMAIN_TPM_SOURCE_TYPE_FILE:
        virCommandAddArgFormat(cmd, "backend-uri=file://%s",
                               emulator->source_path);
        break;
    case VIR_DOMAIN_TPM_SOURCE_TYPE_DIR:
    case VIR_DOMAIN_TPM_SOURCE_TYPE_DEFAULT:
    case VIR_DOMAIN_TPM_SOURCE_TYPE_LAST:
        virCommandAddArgFormat(cmd, "dir=%s,mode=0600",
                               emulator->source_path);
        break;
    }
}

/* qemuTPMEmulatorUpdateProfileName:
 *
 * @emulator: TPM emulator definition
 * @persistentTPMDef: TPM definition from the persistent domain definition
 * @cfg: virQEMUDriverConfig
 * @saveDef: whether caller should save the persistent domain def
 */
static int
qemuTPMEmulatorUpdateProfileName(virDomainTPMEmulatorDef *emulator,
                                 virDomainTPMDef *persistentTPMDef,
                                 const virQEMUDriverConfig *cfg,
                                 bool *saveDef)
{
    g_autoptr(virJSONValue) object = NULL;
    g_autofree char *stderr_buf = NULL;
    g_autofree char *stdout_buf = NULL;
    g_autoptr(virCommand) cmd = NULL;
    g_autofree char *swtpm = NULL;
    virJSONValue *active_profile;
    const char *profile_name;
    int exitstatus;

    if (emulator->version != VIR_DOMAIN_TPM_VERSION_2_0 ||
        !virTPMSwtpmCapsGet(VIR_TPM_SWTPM_FEATURE_CMDARG_PRINT_INFO))
        return 0;

    swtpm = virTPMGetSwtpm();
    if (!swtpm)
        return -1;

    cmd = virCommandNew(swtpm);

    virCommandSetUID(cmd, cfg->swtpm_user); /* should be uid of 'tss' or 'root' */
    virCommandSetGID(cmd, cfg->swtpm_group);

    virCommandAddArgList(cmd, "socket", "--print-info", "0x20", "--tpm2", NULL);

    qemuTPMVirCommandSwtpmAddTPMState(cmd, emulator);

    if (qemuTPMVirCommandSwtpmAddEncryption(cmd, emulator, swtpm) < 0)
        return -1;

    virCommandClearCaps(cmd);

    virCommandSetOutputBuffer(cmd, &stdout_buf);
    virCommandSetErrorBuffer(cmd, &stderr_buf);

    if (virCommandRun(cmd, &exitstatus) < 0 || exitstatus != 0) {
        virReportError(VIR_ERR_INTERNAL_ERROR,
                       _("Could not run '%1$s --print-info'. exitstatus: %2$d; stderr: %3$s"),
                          swtpm, exitstatus, stderr_buf);
        return -1;
    }

    if (!(object = virJSONValueFromString(stdout_buf)))
        return -1;

    if (!(active_profile = virJSONValueObjectGetObject(object, "ActiveProfile")))
        return -1;

    profile_name = virJSONValueObjectGetString(active_profile, "Name");

    g_free(emulator->profile.name);
    emulator->profile.name = g_strdup(profile_name);

    *saveDef = true;
    g_free(persistentTPMDef->data.emulator.profile.name);
    persistentTPMDef->data.emulator.profile.name = g_strdup(profile_name);

    return 0;
}

/*
 * qemuTPMEmulatorBuildCommand:
 *
 * @tpm: TPM definition
 * @persistentTPMDef: TPM definition from the persistent domain definition
 * @vmname: The name of the VM
 * @vmuuid: The UUID of the VM
 * @privileged: whether we are running in privileged mode
 * @cfg: virQEMUDriverConfig
 * @incomingMigration: whether we have an incoming migration
 * @saveDef: whether caller should save the persistent domain def
 *
 * Create the virCommand use for starting the emulator
 * Do some initializations on the way, such as creation of storage
 * and emulator setup.
 */
static virCommand *
qemuTPMEmulatorBuildCommand(virDomainTPMDef *tpm,
                            virDomainTPMDef *persistentTPMDef,
                            const char *vmname,
                            const unsigned char *vmuuid,
                            bool privileged,
                            const virQEMUDriverConfig *cfg,
                            bool incomingMigration,
                            bool *saveDef)
{
    g_autoptr(virCommand) cmd = NULL;
    bool created = false;
    bool run_setup = false;
    g_autofree char *swtpm = virTPMGetSwtpm();
    const unsigned char *secretuuid = NULL;
    bool create_storage = true;
    bool on_shared_storage;

    if (!swtpm)
        return NULL;

    if (tpm->data.emulator.source_type == VIR_DOMAIN_TPM_SOURCE_TYPE_FILE) {
        if (!virTPMSwtpmCapsGet(VIR_TPM_SWTPM_FEATURE_NVRAM_BACKEND_DIR)) {
            virReportError(VIR_ERR_ARGUMENT_UNSUPPORTED,
                           _("%1$s does not support file storage"),
                           swtpm);
            goto error;
        }
        create_storage = false;
        /* setup is run with --not-overwrite */
        run_setup = true;
    }

    /* Do not create storage and run swtpm_setup on incoming migration over
     * shared storage
     */
    on_shared_storage = virFileIsSharedFS(tpm->data.emulator.source_path,
                                          cfg->sharedFilesystems) == 1;
    if (incomingMigration && on_shared_storage)
        create_storage = false;

    if (create_storage) {
        if (qemuTPMEmulatorCreateStorage(tpm, &created,
                                         cfg->swtpm_user, cfg->swtpm_group) < 0)
            return NULL;
        run_setup = created;
    }

    if (tpm->data.emulator.hassecretuuid)
        secretuuid = tpm->data.emulator.secretuuid;

    if (run_setup &&
        qemuTPMEmulatorRunSetup(&tpm->data.emulator, vmname, vmuuid,
                                privileged, cfg,  secretuuid,
                                incomingMigration) < 0)
        goto error;

    if (run_setup && !incomingMigration &&
        qemuTPMEmulatorUpdateProfileName(&tpm->data.emulator, persistentTPMDef,
                                         cfg, saveDef) < 0)
        goto error;

    if (!incomingMigration &&
        qemuTPMEmulatorReconfigure(&tpm->data.emulator, cfg, secretuuid) < 0)
        goto error;

    unlink(tpm->data.emulator.source->data.nix.path);

    cmd = virCommandNew(swtpm);

    virCommandClearCaps(cmd);

    virCommandAddArgList(cmd, "socket", "--ctrl", NULL);
    virCommandAddArgFormat(cmd, "type=unixio,path=%s,mode=0600",
                           tpm->data.emulator.source->data.nix.path);

    qemuTPMVirCommandSwtpmAddTPMState(cmd, &tpm->data.emulator);

    virCommandAddArg(cmd, "--log");
    if (tpm->data.emulator.debug != 0)
        virCommandAddArgFormat(cmd, "file=%s,level=%u", tpm->data.emulator.logfile,
                               tpm->data.emulator.debug);
    else
        virCommandAddArgFormat(cmd, "file=%s", tpm->data.emulator.logfile);

    virCommandAddArg(cmd, "--terminate");

    virCommandSetUID(cmd, cfg->swtpm_user);
    virCommandSetGID(cmd, cfg->swtpm_group);

    switch (tpm->data.emulator.version) {
    case VIR_DOMAIN_TPM_VERSION_1_2:
        break;
    case VIR_DOMAIN_TPM_VERSION_2_0:
        virCommandAddArg(cmd, "--tpm2");
        break;
    case VIR_DOMAIN_TPM_VERSION_DEFAULT:
    case VIR_DOMAIN_TPM_VERSION_LAST:
        break;
    }

    if (qemuTPMVirCommandSwtpmAddEncryption(cmd,
                                            &tpm->data.emulator,
                                            swtpm) < 0)
        goto error;

    /* If swtpm supports it and the TPM state is stored on shared storage,
     * start swtpm with --migration release-lock-outgoing so it can migrate
     * across shared storage if needed.
     */
    QEMU_DOMAIN_TPM_PRIVATE(tpm)->swtpm.can_migrate_shared_storage = false;
    if (on_shared_storage &&
        virTPMSwtpmCapsGet(VIR_TPM_SWTPM_FEATURE_CMDARG_MIGRATION)) {

        virCommandAddArg(cmd, "--migration");
        virCommandAddArgFormat(cmd, "release-lock-outgoing%s",
                               incomingMigration ? ",incoming": "");
        QEMU_DOMAIN_TPM_PRIVATE(tpm)->swtpm.can_migrate_shared_storage = true;
    } else {
        /* Report an error if there's an incoming migration across shared
         * storage and swtpm does not support the --migration option.
         */
        if (incomingMigration && on_shared_storage) {
            virReportError(VIR_ERR_ARGUMENT_UNSUPPORTED,
                           _("%1$s (on destination side) does not support the --migration option needed for migration with shared storage"),
                           swtpm);
            goto error;
        }
    }

    return g_steal_pointer(&cmd);

 error:
    if (created)
        qemuTPMEmulatorDeleteStorage(tpm);

    return NULL;
}


/* --------------------
 *  High-level actions
 * --------------------
 *
 * Each of these corresponds to one of the public entry points
 * defined below, but operates on a single TPM device instead of the
 * entire VM.
 */


/*
 * qemuTPMEmulatorInitPaths:
 *
 * @tpm: TPM definition for an emulator type
 * @swtpmStorageDir: the general swtpm storage dir which is used as a base
 *                   directory for creating VM specific directories
 * @logDir: directory where swtpm writes its logs into
 * @vmname: name of the VM
 * @uuid: the UUID of the VM
 */
static int
qemuTPMEmulatorInitPaths(virDomainTPMDef *tpm,
                         const char *swtpmStorageDir,
                         const char *logDir,
                         const char *vmname,
                         const unsigned char *uuid)
{
    char uuidstr[VIR_UUID_STRING_BUFLEN];

    virUUIDFormat(uuid, uuidstr);

    if (!tpm->data.emulator.source_path &&
        !(tpm->data.emulator.source_path =
            qemuTPMEmulatorStorageBuildPath(swtpmStorageDir, uuidstr,
                                            tpm->data.emulator.version)))
        return -1;

    if (!tpm->data.emulator.logfile) {
        tpm->data.emulator.logfile = qemuTPMEmulatorLogBuildPath(logDir,
                                                                 vmname);
    }

    return 0;
}


/**
 * qemuTPMEmulatorCleanupHost:
 * @driver: QEMU driver
 * @tpm: TPM definition
 * @flags: flags indicating whether to keep or remove TPM persistent state
 * @outgoingMigration: whether cleanup is due to an outgoing migration
 *
 * Clean up persistent storage for the swtpm.
 */
static void
qemuTPMEmulatorCleanupHost(virQEMUDriver *driver,
                           virDomainTPMDef *tpm,
                           virDomainUndefineFlagsValues flags,
                           bool outgoingMigration)
{
    g_autoptr(virQEMUDriverConfig) cfg = virQEMUDriverGetConfig(driver);

    /* Never remove the state in case of outgoing migration with shared
     * storage.
     */
    if (outgoingMigration &&
        virFileIsSharedFS(tpm->data.emulator.source_path, cfg->sharedFilesystems) == 1)
        return;

    /*
     * remove TPM state if:
     * - persistent_state flag is set and the UNDEFINE_TPM flag is set
     * - persistent_state flag is not set and the KEEP_TPM flag is not set
     */
    if ((tpm->data.emulator.persistent_state && (flags & VIR_DOMAIN_UNDEFINE_TPM)) ||
        (!tpm->data.emulator.persistent_state && !(flags & VIR_DOMAIN_UNDEFINE_KEEP_TPM))) {
        qemuTPMEmulatorDeleteStorage(tpm);
    }
}


/*
 * qemuTPMEmulatorPrepareHost:
 *
 * @tpm: tpm definition
 * @logDir: directory where swtpm writes its logs into
 * @swtpm_user: uid to run the swtpm with
 * @swtpm_group: gid to run the swtpm with
 * @swtpmStateDir: directory for swtpm runtime state
 * @qemu_user: uid that qemu will run with; we share the socket file with it
 * @shortName: short and unique name of the domain
 *
 * Prepare the log directory for the swtpm and adjust ownership of it and the
 * log file we will be using. Prepare the state directory where we will share
 * the socket between tss and qemu users.
 */
static int
qemuTPMEmulatorPrepareHost(virDomainTPMDef *tpm,
                           const char *logDir,
                           uid_t swtpm_user,
                           gid_t swtpm_group,
                           const char *swtpmStateDir,
                           uid_t qemu_user,
                           const char *shortName)
{
    /* create log dir ... allow 'tss' user to cd into it */
    if (g_mkdir_with_parents(logDir, 0711) < 0)
        return -1;

    /* ... and adjust ownership */
    if (virDirCreate(logDir, 0730, swtpm_user, swtpm_group,
                     VIR_DIR_CREATE_ALLOW_EXIST) < 0)
        return -1;

    if (!virFileExists(tpm->data.emulator.logfile) &&
        virFileTouch(tpm->data.emulator.logfile, 0644) < 0) {
        return -1;
    }

    /* ... and make sure it can be accessed by swtpm_user */
    if (chown(tpm->data.emulator.logfile, swtpm_user, swtpm_group) < 0) {
        virReportSystemError(errno,
                             _("Could not chown on swtpm logfile %1$s"),
                             tpm->data.emulator.logfile);
        return -1;
    }

    /*
      create our swtpm state dir ...
      - QEMU user needs to be able to access the socket there
      - swtpm group needs to be able to create files there
      - in privileged mode 0570 would be enough, for non-privileged mode
        we need 0770
    */
    if (virDirCreate(swtpmStateDir, 0770, qemu_user, swtpm_group,
                     VIR_DIR_CREATE_ALLOW_EXIST) < 0)
        return -1;

    /* create the socket filename */
    if (!tpm->data.emulator.source->data.nix.path &&
        !(tpm->data.emulator.source->data.nix.path =
          qemuTPMEmulatorSocketBuildPath(swtpmStateDir, shortName)))
        return -1;
    tpm->data.emulator.source->type = VIR_DOMAIN_CHR_TYPE_UNIX;

    return 0;
}


/*
 * qemuTPMEmulatorStop
 * @swtpmStateDir: A directory where the socket is located
 * @shortName: short and unique name of the domain
 *
 * Gracefully stop the swptm
 */
static void
qemuTPMEmulatorStop(const char *swtpmStateDir,
                    const char *shortName)
{
    g_autoptr(virCommand) cmd = NULL;
    g_autofree char *pathname = NULL;
    g_autofree char *errbuf = NULL;
    g_autofree char *swtpm_ioctl = virTPMGetSwtpmIoctl();
    g_autofree char *pidfile = qemuTPMEmulatorPidFileBuildPath(swtpmStateDir,
                                                               shortName);
    if (swtpm_ioctl &&
        (pathname = qemuTPMEmulatorSocketBuildPath(swtpmStateDir, shortName)) &&
        virFileExists(pathname)) {

        cmd = virCommandNewArgList(swtpm_ioctl, "--unix", pathname, "-s", NULL);

        virCommandSetErrorBuffer(cmd, &errbuf);

        ignore_value(virCommandRun(cmd, NULL));

        /* clean up the socket */
        unlink(pathname);
    }

    if (pidfile)
        virPidFileForceCleanupPath(pidfile);
}


/**
 * qemuExtTPMEmulatorSetupCgroup:
 * @swtpmStateDir: directory for swtpm runtime state
 * @shortName: short and unique name of the domain
 * @cgroup: cgroup to add the swtpm process to
 *
 * Add the swtpm process to the appropriate cgroup.
 */
static int
qemuExtTPMEmulatorSetupCgroup(const char *swtpmStateDir,
                              const char *shortName,
                              virCgroup *cgroup)
{
    int rc;
    pid_t pid;

    rc = qemuTPMEmulatorGetPid(swtpmStateDir, shortName, &pid);
    if (rc < 0 || (rc == 0 && pid == (pid_t)-1)) {
        virReportError(VIR_ERR_INTERNAL_ERROR, "%s",
                       _("Could not get process id of swtpm"));
        return -1;
    }

    if (virCgroupAddProcess(cgroup, pid) < 0)
        return -1;

    return 0;
}


/**
 * qemuTPMEmulatorStart:
 * @driver: QEMU driver
 * @vm: the domain object
 * @tpm: TPM definition
 * @persistentTPMDef: TPM definition from persistent domain definition
 * @shortName: short and unique name of the domain
 * @incomingMigration: whether we have an incoming migration
 *
 * Start the external TPM Emulator:
 * - have the command line built
 * - start the external TPM Emulator and sync with it before QEMU start
 */
static int
qemuTPMEmulatorStart(virQEMUDriver *driver,
                     virDomainObj *vm,
                     const char *shortName,
                     virDomainTPMDef *tpm,
                     virDomainTPMDef *persistentTPMDef,
                     bool incomingMigration)
{
    g_autoptr(virCommand) cmd = NULL;
    VIR_AUTOCLOSE errfd = -1;
    g_autoptr(virQEMUDriverConfig) cfg = NULL;
    g_autofree char *pidfile = NULL;
    virTimeBackOffVar timebackoff;
    const unsigned long long timeout = 1000; /* ms */
    bool saveDef = false;
    pid_t pid = -1;
    bool lockMetadataException = false;

    cfg = virQEMUDriverGetConfig(driver);

    /* stop any left-over TPM emulator for this VM */
    qemuTPMEmulatorStop(cfg->swtpmStateDir, shortName);

    if (!(cmd = qemuTPMEmulatorBuildCommand(tpm, persistentTPMDef,
                                            vm->def->name, vm->def->uuid,
                                            driver->privileged,
                                            cfg,
                                            incomingMigration,
                                            &saveDef)))
        return -1;

    if (saveDef &&
        virDomainDefSave(vm->newDef, driver->xmlopt, cfg->configDir) < 0)
        goto error;

    if (qemuExtDeviceLogCommand(driver, vm, cmd, "TPM Emulator") < 0)
        return -1;

    if (!(pidfile = qemuTPMEmulatorPidFileBuildPath(cfg->swtpmStateDir, shortName)))
        return -1;

    virCommandDoAsyncIO(cmd);
    virCommandDaemonize(cmd);
    virCommandSetPidFile(cmd, pidfile);
    virCommandSetErrorFD(cmd, &errfd);

    if (incomingMigration && qemuTPMHasSharedStorage(driver, vm->def)) {
        /* If the TPM is being migrated over shared storage, we can't
         * lock all files before labeling them: the source swtpm
         * process is still holding on to the lock file, and it will
         * only release it after negotiation with the target swtpm
         * process, which we can't start until labeling has been
         * performed.
         *
         * So we explicity request for the lock file not to be locked
         * before labeling in this specific, narrow scenario in order
         * to make migration possible at all */
        lockMetadataException = true;
    }

    if (qemuSecuritySetTPMLabels(driver, vm, true, lockMetadataException) < 0)
        return -1;

    if (qemuSecurityCommandRun(driver, vm, cmd, cfg->swtpm_user,
                               cfg->swtpm_group, false, NULL) < 0) {
        goto error;
    }

    if (virPidFileReadPath(pidfile, &pid) < 0) {
        virReportError(VIR_ERR_INTERNAL_ERROR, "%s",
                       _("swtpm didn't show up"));
        goto error;
    }

    if (virTimeBackOffStart(&timebackoff, 1, timeout) < 0)
        goto error;
    while (virTimeBackOffWait(&timebackoff)) {
        char errbuf[1024] = { 0 };

        if (virFileExists(tpm->data.emulator.source->data.nix.path))
            break;

        if (virProcessKill(pid, 0) == 0)
            continue;

        if (saferead(errfd, errbuf, sizeof(errbuf) - 1) < 0) {
            virReportSystemError(errno, "%s",
                                 _("swtpm died unexpectedly"));
        } else {
            virReportError(VIR_ERR_OPERATION_FAILED,
                           _("swtpm died and reported: %1$s"), errbuf);
        }
        goto error;
    }

    if (!virFileExists(tpm->data.emulator.source->data.nix.path)) {
        virReportError(VIR_ERR_OPERATION_TIMEOUT, "%s",
                       _("swtpm socket did not show up"));
        goto error;
    }

    return 0;

 error:
    virCommandAbort(cmd);
    if (pid >= 0)
        virProcessKillPainfully(pid, true);
    if (pidfile)
        unlink(pidfile);
    qemuSecurityRestoreTPMLabels(driver, vm, true, lockMetadataException);
    return -1;
}


bool
qemuTPMHasSharedStorage(virQEMUDriver *driver,
                        virDomainDef *def)
{
    g_autoptr(virQEMUDriverConfig) cfg = virQEMUDriverGetConfig(driver);
    size_t i;

    for (i = 0; i < def->ntpms; i++) {
        virDomainTPMDef *tpm = def->tpms[i];

        switch (tpm->type) {
        case VIR_DOMAIN_TPM_TYPE_EMULATOR:
            return virFileIsSharedFS(tpm->data.emulator.source_path,
                                     cfg->sharedFilesystems) == 1;
        case VIR_DOMAIN_TPM_TYPE_PASSTHROUGH:
        case VIR_DOMAIN_TPM_TYPE_EXTERNAL:
        case VIR_DOMAIN_TPM_TYPE_LAST:
            break;
        }
    }

    return false;
}


bool
qemuTPMCanMigrateSharedStorage(virDomainDef *def)
{
    size_t i;

    for (i = 0; i < def->ntpms; i++) {
        virDomainTPMDef *tpm = def->tpms[i];
        switch (tpm->type) {
        case VIR_DOMAIN_TPM_TYPE_EMULATOR:
            return QEMU_DOMAIN_TPM_PRIVATE(tpm)->swtpm.can_migrate_shared_storage;
        case VIR_DOMAIN_TPM_TYPE_PASSTHROUGH:
        case VIR_DOMAIN_TPM_TYPE_EXTERNAL:
        case VIR_DOMAIN_TPM_TYPE_LAST:
            break;
        }
    }
    return true;
}


/* ---------------------
 *  Module entry points
 * ---------------------
 *
 * These are the public functions that will be called by other parts
 * of the QEMU driver.
 */


int
qemuExtTPMInitPaths(virQEMUDriver *driver,
                    virDomainDef *def,
                    virDomainTPMDef *tpm)
{
    g_autoptr(virQEMUDriverConfig) cfg = virQEMUDriverGetConfig(driver);

    return qemuTPMEmulatorInitPaths(tpm,
                                    cfg->swtpmStorageDir,
                                    cfg->swtpmLogDir,
                                    def->name,
                                    def->uuid);
}


int
qemuExtTPMPrepareHost(virQEMUDriver *driver,
                      virDomainDef *def,
                      virDomainTPMDef *tpm)
{
    g_autoptr(virQEMUDriverConfig) cfg = virQEMUDriverGetConfig(driver);
    g_autofree char *shortName = virDomainDefGetShortName(def);

    if (!shortName)
        return -1;

    return qemuTPMEmulatorPrepareHost(tpm,
                                      cfg->swtpmLogDir,
                                      cfg->swtpm_user,
                                      cfg->swtpm_group,
                                      cfg->swtpmStateDir,
                                      cfg->user,
                                      shortName);
}


void
qemuExtTPMCleanupHost(virQEMUDriver *driver,
                      virDomainTPMDef *tpm,
                      virDomainUndefineFlagsValues flags,
                      bool outgoingMigration)
{
    qemuTPMEmulatorCleanupHost(driver, tpm, flags, outgoingMigration);
}


int
qemuExtTPMStart(virQEMUDriver *driver,
                virDomainObj *vm,
                virDomainTPMDef *tpm,
                virDomainTPMDef *persistentTPMDef,
                bool incomingMigration)
{
    g_autofree char *shortName = virDomainDefGetShortName(vm->def);

    if (!shortName)
        return -1;

    return qemuTPMEmulatorStart(driver, vm, shortName, tpm, persistentTPMDef,
                                incomingMigration);
}


void
qemuExtTPMStop(virQEMUDriver *driver,
               virDomainObj *vm,
               bool outgoingMigration)
{
    g_autoptr(virQEMUDriverConfig) cfg = virQEMUDriverGetConfig(driver);
    g_autofree char *shortName = virDomainDefGetShortName(vm->def);
    bool restoreTPMStateLabel = true;

    if (!shortName)
        return;

    qemuTPMEmulatorStop(cfg->swtpmStateDir, shortName);
    if (outgoingMigration && qemuTPMHasSharedStorage(driver, vm->def))
        restoreTPMStateLabel = false;

    if (qemuSecurityRestoreTPMLabels(driver, vm, restoreTPMStateLabel, false) < 0)
        VIR_WARN("Unable to restore labels on TPM state and/or log file");
}


int
qemuExtTPMSetupCgroup(virQEMUDriver *driver,
                      virDomainDef *def,
                      virCgroup *cgroup)
{
    g_autoptr(virQEMUDriverConfig) cfg = virQEMUDriverGetConfig(driver);
    g_autofree char *shortName = virDomainDefGetShortName(def);

    if (!shortName)
        return -1;

    if (qemuExtTPMEmulatorSetupCgroup(cfg->swtpmStateDir, shortName, cgroup) < 0)
        return -1;

    return 0;
}
