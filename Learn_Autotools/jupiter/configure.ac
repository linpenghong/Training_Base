#                                               -*- Autoconf -*-
# Process this file with autoconf to produce a configure script.

AC_PREREQ([2.69])
AC_INIT([Jupiter], [1.0], [hmx13@mails.tsinghua.edu.cn])
AM_INIT_AUTOMAKE
LT_PREREQ([2.2])
LT_INIT([dlopen])
AC_CONFIG_SRCDIR([src/main.c])
AC_CONFIG_HEADERS([config.h])

# Checks for programs.
AC_PROG_CC

_DEBUG_START_
AC_CHECK_PROG([bash_var], [bash], [yes], [no],, [/usr/sbin/bash])
_DEBUG_END_

AC_PROG_INSTALL
# AC_PROG_RANLIB
AM_PROG_CC_C_O

# Checks for libraries.
have_pthreads=no
AC_SEARCH_LIBS([pthread_create], [phtread], [have_pthreads=yes])

# Checks for header files.
AC_CHECK_HEADERS([stdlib.h])

if test "x${have_pthreads}" = xyes; then
    AC_CHECK_HEADER([pthread.h], [], [have_pthreads=no])
fi

if test "x${have_pthreads}" = xno; then
    AC_MSG_WARN([Unable to find pthreads on this system.])
fi

# Checks for typedefs, structures, and compiler characteristics.

# Checks for library functions.

AC_CONFIG_FILES([Makefile
                 common/Makefile
                 include/Makefile
                 libjup/Makefile
                 src/Makefile])
AC_OUTPUT
