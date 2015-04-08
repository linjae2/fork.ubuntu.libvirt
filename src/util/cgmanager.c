/*
 * lxc: linux Container library
 *
 * (C) Copyright Canonical Ltd. 2013-2014
 *
 * Authors:
 * Serge Hallyn <serge.hallyn@canonical.com>
 * Stéphane Graber <stephane.graber@canonical.com>
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
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA
 */

#ifdef HAVE_CGMANAGER

#include <config.h>

#include <libgen.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

#include "virutil.h"
#include "viralloc.h"
#include "virerror.h"
#include "virlog.h"
#include "virthread.h"
#include "cgmanager.h"

static NihDBusProxy *cgroup_manager = NULL;
bool cgm_running = false;
static virMutex cgmanager_lock = VIR_MUTEX_INITIALIZER;

VIR_LOG_INIT("util.cgmanager");

#define CGMANAGER_DBUS_SOCK "unix:path=/sys/fs/cgroup/cgmanager/sock"
bool cgm_dbus_connect(void)
{
    DBusError dbus_error;
    DBusConnection *connection;
    dbus_error_init(&dbus_error);

    virMutexLock(&cgmanager_lock);

    connection = dbus_connection_open_private(CGMANAGER_DBUS_SOCK, &dbus_error);
    if (!connection) {
        dbus_error_free(&dbus_error);
	virMutexUnlock(&cgmanager_lock);
        return false;
    }

    dbus_connection_set_exit_on_disconnect(connection, FALSE);
    dbus_error_free(&dbus_error);
    cgroup_manager = nih_dbus_proxy_new(NULL, connection,
                NULL /* p2p */,
                "/org/linuxcontainers/cgmanager", NULL, NULL);
    dbus_connection_unref(connection);
    if (!cgroup_manager) {
        NihError *nerr;
        nerr = nih_error_get();
        VIR_ERROR("cgmanager: Error opening proxy: %s", nerr->message);
        nih_free(nerr);
	virMutexUnlock(&cgmanager_lock);
        return false;
    }

    // force fd passing negotiation
    if (cgmanager_ping_sync(NULL, cgroup_manager, 0) != 0) {
        NihError *nerr;
        nerr = nih_error_get();
        VIR_ERROR("cgmanager: Error pinging manager: %s", nerr->message);
        nih_free(nerr);
        nih_free(cgroup_manager);
        cgroup_manager = NULL;
	virMutexUnlock(&cgmanager_lock);
        return false;
    }
    cgm_running = true;
    return true;
}

void cgm_dbus_disconnect(void)
{
    if (cgroup_manager) {
        dbus_connection_flush(cgroup_manager->connection);
        dbus_connection_close(cgroup_manager->connection);
        nih_free(cgroup_manager);
        cgroup_manager = NULL;
	virMutexUnlock(&cgmanager_lock);
    }
}

bool cgm_create(const char *controller, const char *cgroup_path, int32_t *existed)
{
    if (cgroup_path[0] == '/')
        cgroup_path++;

    if ( cgmanager_create_sync(NULL, cgroup_manager, controller,
                       cgroup_path, existed) != 0) {
        NihError *nerr;
        nerr = nih_error_get();
        VIR_ERROR("cgmanager: cgm_create for controller=%s, cgroup_path=%s failed: %s",
                  controller, cgroup_path, nerr->message);
        nih_free(nerr);
        return false;
    }

    return true;
}

bool cgm_remove(const char *controller, const char *cgroup_path, int recursive)
{
    int existed;

    if (cgroup_path[0] == '/')
        cgroup_path++;

    if ( cgmanager_remove_sync(NULL, cgroup_manager, controller,
                   cgroup_path, recursive, &existed) != 0) {
        NihError *nerr;
        nerr = nih_error_get();
        VIR_ERROR("cgmanager: cgm_remove for controller=%s, cgroup_path=%s, recursive=%d failed: %s",
                  controller, cgroup_path, recursive, nerr->message);
        nih_free(nerr);
        return false;
    }

    if (existed == -1) {
        VIR_ERROR("cgmanager: cgm_remove failed: %s:%s did not exist", controller, cgroup_path);
        return false;
    }
    return true;
}

char *cgm_get(const char *controller, const char *cgroup_path, const char *key)
{
    char *result = NULL;

    if (cgroup_path[0] == '/')
        cgroup_path++;

    if (cgmanager_get_value_sync(NULL, cgroup_manager, controller, cgroup_path, key, &result) != 0) {
        NihError *nerr;
        nerr = nih_error_get();
        VIR_ERROR("cgmanager: cgm_get for controller=%s, cgroup_path=%s failed: %s",
                  controller, cgroup_path, nerr->message);
        nih_free(nerr);
        free(result);
        return NULL;
    }
    return result;
}

bool cgm_set(const char *controller, const char *cgroup_path, const char *key, const char *val)
{
    if (cgroup_path[0] == '/')
        cgroup_path++;

    if (cgmanager_set_value_sync(NULL, cgroup_manager, controller, cgroup_path, key, val) != 0) {
        NihError *nerr;
        nerr = nih_error_get();
        VIR_ERROR("cgmanager: cgm_set for controller=%s, cgroup_path=%s failed: %s",
                  controller, cgroup_path, nerr->message);
        nih_free(nerr);
        return false;
    }
    return true;
}

bool cgm_chmod(const char *controller, const char *cgroup_path, int mode)
{
    nih_local char *path_dirname = NULL;
    nih_local char *path_basename = NULL;

    if (cgroup_path[0] == '/')
        cgroup_path++;

    path_dirname = NIH_MUST(nih_strdup(NULL, cgroup_path));
    path_basename = NIH_MUST(nih_strdup(NULL, cgroup_path));

    if (cgmanager_chmod_sync(NULL, cgroup_manager, controller,
            dirname(path_dirname), basename(path_basename), mode) != 0) {
        NihError *nerr;
        nerr = nih_error_get();
        VIR_ERROR("cgmanager: cgm_chmod for controller=%s, cgroup_path=%s, mode=%d failed: %s",
                  controller, cgroup_path, mode, nerr->message);
        nih_free(nerr);
        return false;
    }

    return true;
}

bool cgm_chown(const char *controller, const char *cgroup_path, int uid, int gid)
{
    if (cgroup_path[0] == '/')
        cgroup_path++;

    if (cgmanager_chown_sync(NULL, cgroup_manager, controller,
            cgroup_path, uid, gid) != 0) {
        NihError *nerr;
        nerr = nih_error_get();
        VIR_ERROR("cgmanager: cgm_chown for controller=%s, cgroup_path=%s, uid=%d, gid=%d failed: %s",
                  controller, cgroup_path, uid, gid, nerr->message);
        nih_free(nerr);
        return false;
    }

    return true;
}

bool cgm_list_children(const char *controller, const char *cgroup_path, char ***children)
{
    if (cgroup_path[0] == '/')
        cgroup_path++;

    if ( cgmanager_list_children_sync(NULL, cgroup_manager, controller,
                       cgroup_path, children) != 0) {
        NihError *nerr;
        nerr = nih_error_get();
        VIR_ERROR("cgmanager: cgm_list_children for controller=%s, cgroup_path=%s failed: %s",
                  controller, cgroup_path, nerr->message);
        nih_free(nerr);
        return false;
    }

    return true;
}

/*
 * caller must nih_free(pids) when done
 */
bool cgm_get_tasks(const char *controller, const char *cgroup_path, pid_t **pids, size_t *nrpids)
{
    int ret;
    if (cgroup_path[0] == '/')
        cgroup_path++;

    ret = cgmanager_get_tasks_sync(NULL, cgroup_manager, controller, cgroup_path, pids, nrpids);
    if (ret) {
        NihError *nerr;
        nerr = nih_error_get();
        VIR_ERROR("cgmanager: cgm_get_tasks for controller=%s, cgroup_path=%s failed: %s",
                  controller, cgroup_path, nerr->message);
        nih_free(nerr);
        return false;
    }

    return true;
}


/*
 * caller of cgm_get_pid_cgroup must nih_free(path) if we
 * returned true
 */
bool cgm_get_pid_cgroup(const char *controller, pid_t pid, char **cgpath)
{
    *cgpath = NULL;
    if ( cgmanager_get_pid_cgroup_sync(NULL, cgroup_manager, controller,
                        pid, cgpath) != 0) {
        NihError *nerr;
        nerr = nih_error_get();
        nih_free(nerr);
        return false;
    }

    return true;
}

/*
 * caller of cgm_get_pid_cgroup_abs must nih_free(path) if we
 * returned true
 */
bool cgm_get_pid_cgroup_abs(const char *controller, pid_t pid, char **cgpath)
{
    *cgpath = NULL;
    if ( cgmanager_get_pid_cgroup_abs_sync(NULL, cgroup_manager, controller,
                        pid, cgpath) != 0) {
        NihError *nerr;
        nerr = nih_error_get();
        nih_free(nerr);
        return false;
    }

    return true;
}

bool cgm_controller_exists(const char *controller)
{
    char *cgroup_name = NULL;

    if ( cgmanager_get_pid_cgroup_sync(NULL, cgroup_manager, controller,
                        getpid(), &cgroup_name) != 0) {
        NihError *nerr;
        nerr = nih_error_get();
        nih_free(nerr);
        return false;
    }

    nih_free(cgroup_name);
    return true;
}

bool cgm_enter(const char *controller, const char *cgroup_path, pid_t pid)
{
    if (cgroup_path[0] == '/')
        cgroup_path++;

    if (cgmanager_move_pid_sync(NULL, cgroup_manager, controller,
            cgroup_path, pid) != 0) {
        NihError *nerr;
        nerr = nih_error_get();
        VIR_ERROR("cgmanager: cgm_enter for controller=%s, cgroup_path=%s, pid=%d failed: %s",
                  controller, cgroup_path, pid, nerr->message);
        nih_free(nerr);
        return false;
    }
    return true;
}

bool cgm_escape(const char *controller)
{
    if (cgmanager_move_pid_sync(NULL, cgroup_manager, controller, "/",
             getpid()) != 0) {
        NihError *nerr;
        nerr = nih_error_get();
        VIR_DEBUG("cgmanager: Failed escaping to root cgroup for controller %s: %s",
                  controller, nerr->message);
        nih_free(nerr);
    }
    return true;
}
#endif
