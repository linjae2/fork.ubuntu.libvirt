# -*- buffer-read-only: t -*- vi: set ro:
# DO NOT EDIT! GENERATED AUTOMATICALLY!
# fclose.m4 serial 4
dnl Copyright (C) 2008-2011 Free Software Foundation, Inc.
dnl This file is free software; the Free Software Foundation
dnl gives unlimited permission to copy and/or distribute it,
dnl with or without modifications, as long as this notice is preserved.

AC_DEFUN([gl_FUNC_FCLOSE],
[
  gl_FUNC_FFLUSH_STDIN
  if test $gl_cv_func_fflush_stdin = no; then
    gl_REPLACE_FCLOSE
  fi
])

AC_DEFUN([gl_REPLACE_FCLOSE],
[
  AC_REQUIRE([gl_STDIO_H_DEFAULTS])
  REPLACE_FCLOSE=1
  AC_LIBOBJ([fclose])
])
