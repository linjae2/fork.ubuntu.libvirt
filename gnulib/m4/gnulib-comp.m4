# DO NOT EDIT! GENERATED AUTOMATICALLY!
# Copyright (C) 2002-2008 Free Software Foundation, Inc.
#
# This file is free software, distributed under the terms of the GNU
# General Public License.  As a special exception to the GNU General
# Public License, this file may be distributed as part of a program
# that contains a configuration script generated by Autoconf, under
# the same distribution terms as the rest of that program.
#
# Generated by gnulib-tool.
#
# This file represents the compiled summary of the specification in
# gnulib-cache.m4. It lists the computed macro invocations that need
# to be invoked from configure.ac.
# In projects using CVS, this file can be treated like other built files.


# This macro should be invoked from ./configure.in, in the section
# "Checks for programs", right after AC_PROG_CC, and certainly before
# any checks for libraries, header files, types and library functions.
AC_DEFUN([gl_EARLY],
[
  m4_pattern_forbid([^gl_[A-Z]])dnl the gnulib macro namespace
  m4_pattern_allow([^gl_ES$])dnl a valid locale name
  m4_pattern_allow([^gl_LIBOBJS$])dnl a variable
  m4_pattern_allow([^gl_LTLIBOBJS$])dnl a variable
  AC_REQUIRE([AC_PROG_RANLIB])
  AC_REQUIRE([AC_GNU_SOURCE])
  AC_REQUIRE([gl_USE_SYSTEM_EXTENSIONS])
  AC_REQUIRE([AC_FUNC_FSEEKO])
])

# This macro should be invoked from ./configure.in, in the section
# "Check for header files, types and library functions".
AC_DEFUN([gl_INIT],
[
  AM_CONDITIONAL([GL_COND_LIBTOOL], [true])
  gl_cond_libtool=true
  m4_pushdef([AC_LIBOBJ], m4_defn([gl_LIBOBJ]))
  m4_pushdef([AC_REPLACE_FUNCS], m4_defn([gl_REPLACE_FUNCS]))
  m4_pushdef([AC_LIBSOURCES], m4_defn([gl_LIBSOURCES]))
  m4_pushdef([gl_LIBSOURCES_LIST], [])
  m4_pushdef([gl_LIBSOURCES_DIR], [])
  gl_COMMON
  gl_source_base='gnulib/lib'
changequote(,)dnl
LTALLOCA=`echo "$ALLOCA" | sed 's/\.[^.]* /.lo /g;s/\.[^.]*$/.lo/'`
changequote([, ])dnl
AC_SUBST([LTALLOCA])
  gl_FUNC_ALLOCA
  gl_HEADER_ARPA_INET
  AC_PROG_MKDIR_P
  gl_FUNC_CLOSE
  gl_UNISTD_MODULE_INDICATOR([close])
  AC_REQUIRE([gl_HEADER_SYS_SOCKET])
  if test "$ac_cv_header_winsock2_h" = yes; then
    AC_LIBOBJ([connect])
  fi
  gl_SYS_SOCKET_MODULE_INDICATOR([connect])
  gl_HEADER_ERRNO_H
  gl_FUNC_FCLOSE
  gl_STDIO_MODULE_INDICATOR([fclose])
  gl_FLOAT_H
  gl_FUNC_FSEEKO
  gl_STDIO_MODULE_INDICATOR([fseeko])
  gl_GETADDRINFO
  gl_NETDB_MODULE_INDICATOR([getaddrinfo])
  gl_FUNC_GETDELIM
  gl_STDIO_MODULE_INDICATOR([getdelim])
  gl_FUNC_GETHOSTNAME
  gl_UNISTD_MODULE_INDICATOR([gethostname])
  gl_FUNC_GETLINE
  gl_STDIO_MODULE_INDICATOR([getline])
  gl_FUNC_GETPASS
  dnl you must add AM_GNU_GETTEXT([external]) or similar to configure.ac.
  AM_GNU_GETTEXT_VERSION([0.17])
  AC_SUBST([LIBINTL])
  AC_SUBST([LTLIBINTL])
  gl_FUNC_GETTIMEOFDAY
  gl_INET_NTOP
  gl_ARPA_INET_MODULE_INDICATOR([inet_ntop])
  gl_INET_PTON
  gl_ARPA_INET_MODULE_INDICATOR([inet_pton])
  gl_FUNC_LSEEK
  gl_UNISTD_MODULE_INDICATOR([lseek])
  gl_FUNC_LSTAT
  gl_SYS_STAT_MODULE_INDICATOR([lstat])
  gl_FUNC_MALLOC_POSIX
  gl_STDLIB_MODULE_INDICATOR([malloc-posix])
  gl_FUNC_MKSTEMP
  gl_STDLIB_MODULE_INDICATOR([mkstemp])
  gl_HEADER_NETDB
  gl_HEADER_NETINET_IN
  AC_PROG_MKDIR_P
  gl_FUNC_PERROR
  gl_STRING_MODULE_INDICATOR([perror])
  gl_PHYSMEM
  gl_FUNC_POLL
  gl_POSIX_SHELL
  gl_FUNC_REALLOC_POSIX
  gl_STDLIB_MODULE_INDICATOR([realloc-posix])
  AC_REQUIRE([gl_HEADER_SYS_SOCKET])
  if test "$ac_cv_header_winsock2_h" = yes; then
    AC_LIBOBJ([recv])
  fi
  gl_SYS_SOCKET_MODULE_INDICATOR([recv])
  AC_REQUIRE([gl_HEADER_SYS_SOCKET])
  if test "$ac_cv_header_winsock2_h" = yes; then
    AC_LIBOBJ([send])
  fi
  gl_SYS_SOCKET_MODULE_INDICATOR([send])
  AC_REQUIRE([gl_HEADER_SYS_SOCKET])
  if test "$ac_cv_header_winsock2_h" = yes; then
    AC_LIBOBJ([setsockopt])
  fi
  gl_SYS_SOCKET_MODULE_INDICATOR([setsockopt])
  gl_SIZE_MAX
  gl_FUNC_SNPRINTF
  gl_STDIO_MODULE_INDICATOR([snprintf])
  AC_REQUIRE([gl_HEADER_SYS_SOCKET])
  if test "$ac_cv_header_winsock2_h" = yes; then
    AC_LIBOBJ([socket])
  fi
  gl_SYS_SOCKET_MODULE_INDICATOR([socket])
  gl_TYPE_SOCKLEN_T
  AM_STDBOOL_H
  gl_STDINT_H
  gl_STDIO_H
  gl_STDLIB_H
  gl_FUNC_STRDUP_POSIX
  gl_STRING_MODULE_INDICATOR([strdup])
  gl_FUNC_STRERROR
  gl_STRING_MODULE_INDICATOR([strerror])
  gl_HEADER_STRING_H
  gl_FUNC_STRNDUP
  gl_STRING_MODULE_INDICATOR([strndup])
  gl_FUNC_STRNLEN
  gl_STRING_MODULE_INDICATOR([strnlen])
  gl_FUNC_STRPBRK
  gl_STRING_MODULE_INDICATOR([strpbrk])
  gl_FUNC_STRSEP
  gl_STRING_MODULE_INDICATOR([strsep])
  gl_HEADER_SYS_SELECT
  AC_PROG_MKDIR_P
  gl_HEADER_SYS_SOCKET
  gl_MODULE_INDICATOR([sys_socket])
  AC_PROG_MKDIR_P
  gl_HEADER_SYS_STAT_H
  AC_PROG_MKDIR_P
  gl_HEADER_SYS_TIME_H
  AC_PROG_MKDIR_P
  gl_FUNC_GEN_TEMPNAME
  gl_UNISTD_H
  gl_FUNC_VASNPRINTF
  gl_FUNC_VASPRINTF
  gl_STDIO_MODULE_INDICATOR([vasprintf])
  m4_ifdef([AM_XGETTEXT_OPTION],
    [AM_XGETTEXT_OPTION([--flag=asprintf:2:c-format])
     AM_XGETTEXT_OPTION([--flag=vasprintf:2:c-format])])
  gl_WCHAR_H
  gl_XSIZE
  m4_ifval(gl_LIBSOURCES_LIST, [
    m4_syscmd([test ! -d ]m4_defn([gl_LIBSOURCES_DIR])[ ||
      for gl_file in ]gl_LIBSOURCES_LIST[ ; do
        if test ! -r ]m4_defn([gl_LIBSOURCES_DIR])[/$gl_file ; then
          echo "missing file ]m4_defn([gl_LIBSOURCES_DIR])[/$gl_file" >&2
          exit 1
        fi
      done])dnl
      m4_if(m4_sysval, [0], [],
        [AC_FATAL([expected source file, required through AC_LIBSOURCES, not found])])
  ])
  m4_popdef([gl_LIBSOURCES_DIR])
  m4_popdef([gl_LIBSOURCES_LIST])
  m4_popdef([AC_LIBSOURCES])
  m4_popdef([AC_REPLACE_FUNCS])
  m4_popdef([AC_LIBOBJ])
  AC_CONFIG_COMMANDS_PRE([
    gl_libobjs=
    gl_ltlibobjs=
    if test -n "$gl_LIBOBJS"; then
      # Remove the extension.
      sed_drop_objext='s/\.o$//;s/\.obj$//'
      for i in `for i in $gl_LIBOBJS; do echo "$i"; done | sed "$sed_drop_objext" | sort | uniq`; do
        gl_libobjs="$gl_libobjs $i.$ac_objext"
        gl_ltlibobjs="$gl_ltlibobjs $i.lo"
      done
    fi
    AC_SUBST([gl_LIBOBJS], [$gl_libobjs])
    AC_SUBST([gl_LTLIBOBJS], [$gl_ltlibobjs])
  ])
  gltests_libdeps=
  gltests_ltlibdeps=
  m4_pushdef([AC_LIBOBJ], m4_defn([gltests_LIBOBJ]))
  m4_pushdef([AC_REPLACE_FUNCS], m4_defn([gltests_REPLACE_FUNCS]))
  m4_pushdef([AC_LIBSOURCES], m4_defn([gltests_LIBSOURCES]))
  m4_pushdef([gltests_LIBSOURCES_LIST], [])
  m4_pushdef([gltests_LIBSOURCES_DIR], [])
  gl_COMMON
  gl_source_base='gnulib/tests'
  AC_REQUIRE([gl_HEADER_SYS_SOCKET])
  if test "$ac_cv_header_winsock2_h" = yes; then
    AC_LIBOBJ([accept])
  fi
  gl_SYS_SOCKET_MODULE_INDICATOR([accept])
  AC_REQUIRE([gl_HEADER_SYS_SOCKET])
  if test "$ac_cv_header_winsock2_h" = yes; then
    AC_LIBOBJ([bind])
  fi
  gl_SYS_SOCKET_MODULE_INDICATOR([bind])
  AC_REQUIRE([gl_HEADER_SYS_SOCKET])
  if test "$ac_cv_header_winsock2_h" = yes; then
    AC_LIBOBJ([ioctl])
    gl_REPLACE_SYS_IOCTL_H
  fi
  gl_SYS_IOCTL_MODULE_INDICATOR([ioctl])
  gl_MODULE_INDICATOR([ioctl])
  AC_REQUIRE([gl_HEADER_SYS_SOCKET])
  if test "$ac_cv_header_winsock2_h" = yes; then
    AC_LIBOBJ([listen])
  fi
  gl_SYS_SOCKET_MODULE_INDICATOR([listen])
  AC_CHECK_HEADERS_ONCE([unistd.h sys/wait.h])
  gl_SOCKETS
  gt_TYPE_WCHAR_T
  gt_TYPE_WINT_T
  gl_SYS_IOCTL_H
  AC_PROG_MKDIR_P
  AC_CHECK_FUNCS([shutdown])
  abs_aux_dir=`cd "$ac_aux_dir"; pwd`
  AC_SUBST([abs_aux_dir])
  m4_ifval(gltests_LIBSOURCES_LIST, [
    m4_syscmd([test ! -d ]m4_defn([gltests_LIBSOURCES_DIR])[ ||
      for gl_file in ]gltests_LIBSOURCES_LIST[ ; do
        if test ! -r ]m4_defn([gltests_LIBSOURCES_DIR])[/$gl_file ; then
          echo "missing file ]m4_defn([gltests_LIBSOURCES_DIR])[/$gl_file" >&2
          exit 1
        fi
      done])dnl
      m4_if(m4_sysval, [0], [],
        [AC_FATAL([expected source file, required through AC_LIBSOURCES, not found])])
  ])
  m4_popdef([gltests_LIBSOURCES_DIR])
  m4_popdef([gltests_LIBSOURCES_LIST])
  m4_popdef([AC_LIBSOURCES])
  m4_popdef([AC_REPLACE_FUNCS])
  m4_popdef([AC_LIBOBJ])
  AC_CONFIG_COMMANDS_PRE([
    gltests_libobjs=
    gltests_ltlibobjs=
    if test -n "$gltests_LIBOBJS"; then
      # Remove the extension.
      sed_drop_objext='s/\.o$//;s/\.obj$//'
      for i in `for i in $gltests_LIBOBJS; do echo "$i"; done | sed "$sed_drop_objext" | sort | uniq`; do
        gltests_libobjs="$gltests_libobjs $i.$ac_objext"
        gltests_ltlibobjs="$gltests_ltlibobjs $i.lo"
      done
    fi
    AC_SUBST([gltests_LIBOBJS], [$gltests_libobjs])
    AC_SUBST([gltests_LTLIBOBJS], [$gltests_ltlibobjs])
  ])
  LIBTESTS_LIBDEPS="$gltests_libdeps"
  AC_SUBST([LIBTESTS_LIBDEPS])
])

# Like AC_LIBOBJ, except that the module name goes
# into gl_LIBOBJS instead of into LIBOBJS.
AC_DEFUN([gl_LIBOBJ], [
  AS_LITERAL_IF([$1], [gl_LIBSOURCES([$1.c])])dnl
  gl_LIBOBJS="$gl_LIBOBJS $1.$ac_objext"
])

# Like AC_REPLACE_FUNCS, except that the module name goes
# into gl_LIBOBJS instead of into LIBOBJS.
AC_DEFUN([gl_REPLACE_FUNCS], [
  m4_foreach_w([gl_NAME], [$1], [AC_LIBSOURCES(gl_NAME[.c])])dnl
  AC_CHECK_FUNCS([$1], , [gl_LIBOBJ($ac_func)])
])

# Like AC_LIBSOURCES, except the directory where the source file is
# expected is derived from the gnulib-tool parameterization,
# and alloca is special cased (for the alloca-opt module).
# We could also entirely rely on EXTRA_lib..._SOURCES.
AC_DEFUN([gl_LIBSOURCES], [
  m4_foreach([_gl_NAME], [$1], [
    m4_if(_gl_NAME, [alloca.c], [], [
      m4_define([gl_LIBSOURCES_DIR], [gnulib/lib])
      m4_append([gl_LIBSOURCES_LIST], _gl_NAME, [ ])
    ])
  ])
])

# Like AC_LIBOBJ, except that the module name goes
# into gltests_LIBOBJS instead of into LIBOBJS.
AC_DEFUN([gltests_LIBOBJ], [
  AS_LITERAL_IF([$1], [gltests_LIBSOURCES([$1.c])])dnl
  gltests_LIBOBJS="$gltests_LIBOBJS $1.$ac_objext"
])

# Like AC_REPLACE_FUNCS, except that the module name goes
# into gltests_LIBOBJS instead of into LIBOBJS.
AC_DEFUN([gltests_REPLACE_FUNCS], [
  m4_foreach_w([gl_NAME], [$1], [AC_LIBSOURCES(gl_NAME[.c])])dnl
  AC_CHECK_FUNCS([$1], , [gltests_LIBOBJ($ac_func)])
])

# Like AC_LIBSOURCES, except the directory where the source file is
# expected is derived from the gnulib-tool parameterization,
# and alloca is special cased (for the alloca-opt module).
# We could also entirely rely on EXTRA_lib..._SOURCES.
AC_DEFUN([gltests_LIBSOURCES], [
  m4_foreach([_gl_NAME], [$1], [
    m4_if(_gl_NAME, [alloca.c], [], [
      m4_define([gltests_LIBSOURCES_DIR], [gnulib/tests])
      m4_append([gltests_LIBSOURCES_LIST], _gl_NAME, [ ])
    ])
  ])
])

# This macro records the list of files which have been installed by
# gnulib-tool and may be removed by future gnulib-tool invocations.
AC_DEFUN([gl_FILE_LIST], [
  build-aux/config.rpath
  build-aux/link-warning.h
  build-aux/mktempd
  build-aux/useless-if-before-free
  build-aux/vc-list-files
  lib/alloca.c
  lib/alloca.in.h
  lib/arpa_inet.in.h
  lib/asnprintf.c
  lib/asprintf.c
  lib/c-ctype.c
  lib/c-ctype.h
  lib/close.c
  lib/connect.c
  lib/errno.in.h
  lib/fclose.c
  lib/float+.h
  lib/float.in.h
  lib/fseeko.c
  lib/gai_strerror.c
  lib/getaddrinfo.c
  lib/getdelim.c
  lib/gethostname.c
  lib/getline.c
  lib/getpass.c
  lib/getpass.h
  lib/gettext.h
  lib/gettimeofday.c
  lib/inet_ntop.c
  lib/inet_pton.c
  lib/intprops.h
  lib/lseek.c
  lib/lstat.c
  lib/malloc.c
  lib/mkstemp.c
  lib/netdb.in.h
  lib/netinet_in.in.h
  lib/perror.c
  lib/physmem.c
  lib/physmem.h
  lib/poll.c
  lib/poll.in.h
  lib/printf-args.c
  lib/printf-args.h
  lib/printf-parse.c
  lib/printf-parse.h
  lib/realloc.c
  lib/recv.c
  lib/send.c
  lib/setsockopt.c
  lib/size_max.h
  lib/snprintf.c
  lib/socket.c
  lib/stdbool.in.h
  lib/stdint.in.h
  lib/stdio-impl.h
  lib/stdio-write.c
  lib/stdio.in.h
  lib/stdlib.in.h
  lib/strdup.c
  lib/strerror.c
  lib/string.in.h
  lib/strndup.c
  lib/strnlen.c
  lib/strpbrk.c
  lib/strsep.c
  lib/sys_select.in.h
  lib/sys_socket.in.h
  lib/sys_stat.in.h
  lib/sys_time.in.h
  lib/tempname.c
  lib/tempname.h
  lib/unistd.in.h
  lib/vasnprintf.c
  lib/vasnprintf.h
  lib/vasprintf.c
  lib/verify.h
  lib/w32sock.h
  lib/wchar.in.h
  lib/xsize.h
  m4/alloca.m4
  m4/arpa_inet_h.m4
  m4/close.m4
  m4/codeset.m4
  m4/errno_h.m4
  m4/extensions.m4
  m4/fclose.m4
  m4/float_h.m4
  m4/fseeko.m4
  m4/getaddrinfo.m4
  m4/getdelim.m4
  m4/gethostname.m4
  m4/getline.m4
  m4/getpass.m4
  m4/gettext.m4
  m4/gettimeofday.m4
  m4/glibc2.m4
  m4/glibc21.m4
  m4/gnulib-common.m4
  m4/iconv.m4
  m4/include_next.m4
  m4/inet_ntop.m4
  m4/inet_pton.m4
  m4/intdiv0.m4
  m4/intl.m4
  m4/intldir.m4
  m4/intlmacosx.m4
  m4/intmax.m4
  m4/intmax_t.m4
  m4/inttypes-pri.m4
  m4/inttypes_h.m4
  m4/lcmessage.m4
  m4/lib-ld.m4
  m4/lib-link.m4
  m4/lib-prefix.m4
  m4/lock.m4
  m4/longlong.m4
  m4/lseek.m4
  m4/lstat.m4
  m4/malloc.m4
  m4/mkstemp.m4
  m4/netdb_h.m4
  m4/netinet_in_h.m4
  m4/nls.m4
  m4/onceonly.m4
  m4/perror.m4
  m4/physmem.m4
  m4/po.m4
  m4/poll.m4
  m4/posix-shell.m4
  m4/printf-posix.m4
  m4/printf.m4
  m4/progtest.m4
  m4/realloc.m4
  m4/size_max.m4
  m4/snprintf.m4
  m4/sockets.m4
  m4/socklen.m4
  m4/sockpfaf.m4
  m4/stdbool.m4
  m4/stdint.m4
  m4/stdint_h.m4
  m4/stdio_h.m4
  m4/stdlib_h.m4
  m4/strdup.m4
  m4/strerror.m4
  m4/string_h.m4
  m4/strndup.m4
  m4/strnlen.m4
  m4/strpbrk.m4
  m4/strsep.m4
  m4/sys_ioctl_h.m4
  m4/sys_select_h.m4
  m4/sys_socket_h.m4
  m4/sys_stat_h.m4
  m4/sys_time_h.m4
  m4/tempname.m4
  m4/threadlib.m4
  m4/uintmax_t.m4
  m4/unistd_h.m4
  m4/vasnprintf.m4
  m4/vasprintf.m4
  m4/visibility.m4
  m4/wchar.m4
  m4/wchar_t.m4
  m4/wint_t.m4
  m4/xsize.m4
  tests/test-alloca-opt.c
  tests/test-arpa_inet.c
  tests/test-c-ctype.c
  tests/test-errno.c
  tests/test-fseeko.c
  tests/test-fseeko.sh
  tests/test-getaddrinfo.c
  tests/test-getdelim.c
  tests/test-gethostname.c
  tests/test-getline.c
  tests/test-gettimeofday.c
  tests/test-lseek.c
  tests/test-lseek.sh
  tests/test-lstat.c
  tests/test-netdb.c
  tests/test-netinet_in.c
  tests/test-perror.c
  tests/test-perror.sh
  tests/test-poll.c
  tests/test-snprintf.c
  tests/test-sockets.c
  tests/test-stdbool.c
  tests/test-stdint.c
  tests/test-stdio.c
  tests/test-stdlib.c
  tests/test-strerror.c
  tests/test-string.c
  tests/test-sys_select.c
  tests/test-sys_socket.c
  tests/test-sys_stat.c
  tests/test-sys_time.c
  tests/test-unistd.c
  tests/test-vasnprintf.c
  tests/test-vasprintf.c
  tests/test-vc-list-files-cvs.sh
  tests/test-vc-list-files-git.sh
  tests/test-wchar.c
  tests=lib/accept.c
  tests=lib/bind.c
  tests=lib/ioctl.c
  tests=lib/listen.c
  tests=lib/sockets.c
  tests=lib/sockets.h
  tests=lib/sys_ioctl.in.h
  tests=lib/w32sock.h
])
