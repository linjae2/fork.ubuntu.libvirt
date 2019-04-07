/*
 * virfilewrapper.c: Wrapper for universal file access
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

#ifndef WIN32

# include <fcntl.h>

# include "viralloc.h"
# include "virfile.h"
# include "virfilewrapper.h"
# include "virmock.h"
# include "virstring.h"


/* Mapping for prefix overrides */
static size_t noverrides;
static const char **overrides;

/* nprefixes == noverrides, but two variables make it easier to use
 * VIR_*_ELEMENT macros */
static size_t nprefixes;
static const char **prefixes;

/* TODO: callbacks */


static int (*real_open)(const char *path, int flags, ...);
static FILE *(*real_fopen)(const char *path, const char *mode);
static int (*real_access)(const char *path, int mode);
static int (*real_stat)(const char *path, struct stat *sb);
static int (*real___xstat)(int ver, const char *path, struct stat *sb);
static int (*real_lstat)(const char *path, struct stat *sb);
static int (*real___lxstat)(int ver, const char *path, struct stat *sb);
static int (*real_mkdir)(const char *path, mode_t mode);
static DIR *(*real_opendir)(const char *path);

static void init_syms(void)
{
    if (real_fopen)
        return;

    VIR_MOCK_REAL_INIT(fopen);
    VIR_MOCK_REAL_INIT(access);
    VIR_MOCK_REAL_INIT_ALT(lstat, __lxstat);
    VIR_MOCK_REAL_INIT_ALT(stat, __xstat);
    VIR_MOCK_REAL_INIT(mkdir);
    VIR_MOCK_REAL_INIT(open);
    VIR_MOCK_REAL_INIT(opendir);
}


void
virFileWrapperAddPrefix(const char *prefix,
                        const char *override)
{
    /* Both parameters are mandatory */
    if (!prefix || !override) {
        fprintf(stderr, "Attempt to add invalid path override\n");
        abort();
    }

    init_syms();

    if (VIR_APPEND_ELEMENT_QUIET(prefixes, nprefixes, prefix) < 0 ||
        VIR_APPEND_ELEMENT_QUIET(overrides, noverrides, override) < 0) {
        VIR_FREE(prefixes);
        VIR_FREE(overrides);
        fprintf(stderr, "Unable to add path override for '%s'\n", prefix);
        abort();
    }
}


void
virFileWrapperRemovePrefix(const char *prefix)
{
    size_t i = 0;

    for (i = 0; i < noverrides; i++) {
        if (STREQ(prefixes[i], prefix))
            break;
    }

    if (i == noverrides)
        return;

    VIR_DELETE_ELEMENT(overrides, i, noverrides);
    VIR_DELETE_ELEMENT(prefixes, i, nprefixes);
}

void
virFileWrapperClearPrefixes(void)
{
    nprefixes = 0;
    noverrides = 0;

    VIR_FREE(prefixes);
    VIR_FREE(overrides);
}

static char *
virFileWrapperOverridePrefix(const char *path)
{
    char *ret = NULL;
    size_t i = 0;

    for (i = 0; i < noverrides; i++) {
        const char *tmp = STRSKIP(path, prefixes[i]);

        if (!tmp)
            continue;

        if (virAsprintfQuiet(&ret, "%s%s", overrides[i], tmp) < 0)
            return NULL;

        break;
    }

    if (!ret)
        ignore_value(VIR_STRDUP_QUIET(ret, path));

    return ret;
}


# define PATH_OVERRIDE(newpath, path) \
    do { \
        init_syms(); \
 \
        newpath = virFileWrapperOverridePrefix(path); \
        if (!newpath) \
            abort(); \
    } while (0)


FILE *fopen(const char *path, const char *mode)
{
    VIR_AUTOFREE(char *) newpath = NULL;

    PATH_OVERRIDE(newpath, path);

    return real_fopen(newpath, mode);
}

int access(const char *path, int mode)
{
    VIR_AUTOFREE(char *) newpath = NULL;

    PATH_OVERRIDE(newpath, path);

    return real_access(newpath, mode);
}

# ifdef HAVE___LXSTAT
int __lxstat(int ver, const char *path, struct stat *sb)
{
    VIR_AUTOFREE(char *) newpath = NULL;

    PATH_OVERRIDE(newpath, path);

    return real___lxstat(ver, newpath, sb);
}
# endif /* HAVE___LXSTAT */

int lstat(const char *path, struct stat *sb)
{
    VIR_AUTOFREE(char *) newpath = NULL;

    PATH_OVERRIDE(newpath, path);

    return real_lstat(newpath, sb);
}

# ifdef HAVE___XSTAT
int __xstat(int ver, const char *path, struct stat *sb)
{
    VIR_AUTOFREE(char *) newpath = NULL;

    PATH_OVERRIDE(newpath, path);

    return real___xstat(ver, newpath, sb);
}
# endif /* HAVE___XSTAT */

int stat(const char *path, struct stat *sb)
{
    VIR_AUTOFREE(char *) newpath = NULL;

    PATH_OVERRIDE(newpath, path);

    return real_stat(newpath, sb);
}

int mkdir(const char *path, mode_t mode)
{
    VIR_AUTOFREE(char *) newpath = NULL;

    PATH_OVERRIDE(newpath, path);

    return real_mkdir(newpath, mode);
}

int open(const char *path, int flags, ...)
{
    VIR_AUTOFREE(char *) newpath = NULL;
    va_list ap;
    mode_t mode = 0;

    PATH_OVERRIDE(newpath, path);

    /* The mode argument is mandatory when O_CREAT is set in flags,
     * otherwise the argument is ignored.
     */
    if (flags & O_CREAT) {
        va_start(ap, flags);
        mode = (mode_t) va_arg(ap, int);
        va_end(ap);
    }

    return real_open(newpath, flags, mode);
}

DIR *opendir(const char *path)
{
    VIR_AUTOFREE(char *) newpath = NULL;

    PATH_OVERRIDE(newpath, path);

    return real_opendir(newpath);
}
#endif
