#                                               -*- Autoconf -*-
# Process this file with autoconf to produce a configure script.

AC_PREREQ([2.64])
AC_INIT([xode], [0.1], [])
AM_INIT_AUTOMAKE
AC_CONFIG_SRCDIR([config.h.in])
AC_CONFIG_HEADERS([config.h:config.h.in])

# Checks for programs.
AC_PROG_CC
AC_PROG_YACC
AC_PROG_RANLIB
AC_PROG_LEX

# Checks for libraries.

# Checks for header files.
AC_PATH_X
AC_FUNC_ALLOCA
AC_CHECK_HEADERS([float.h inttypes.h libintl.h limits.h malloc.h stddef.h stdlib.h string.h strings.h unistd.h values.h])

# Checks for typedefs, structures, and compiler characteristics.
AC_HEADER_STDBOOL
AC_C_INLINE
AC_TYPE_INT16_T
AC_TYPE_INT32_T
AC_TYPE_INT8_T
AC_TYPE_PID_T
AC_TYPE_SIZE_T
AC_TYPE_UINT16_T
AC_TYPE_UINT32_T
AC_TYPE_UINT8_T
AC_TYPE_SIGNAL

# Checks for library functions.
AC_FUNC_MALLOC
AC_FUNC_REALLOC
AC_CHECK_FUNCS([floor memset modf pow sqrt strcasecmp strchr strerror lgamma gamma])

AC_CONFIG_FILES([Makefile
                 include/Makefile
                 lib/Makefile
                 ode-examples/Makefile
                 ode/Makefile])
AC_OUTPUT
