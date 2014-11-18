dnl $Id$
dnl config.m4 for extension macro

PHP_ARG_WITH(macro, for macro support,
[  --with-macro             Include macro support])

if test "$PHP_MACRO" != "no"; then
  SEARCH_PATH="/usr/local /usr"
  SEARCH_FOR="include/mcpp_lib.h"
  SEARCH_LIB="libmcpp"

  AC_MSG_CHECKING([for mcpp location])
  for i in $PHP_MACRO $SEARCH_PATH ; do
    if test -r $i/$SEARCH_FOR; then
	  MACRO_INCLUDE_DIR=$i
	  AC_MSG_RESULT(mcpp headers found in $i)
    fi

    if test -r $i/$PHP_LIBDIR/$SEARCH_LIB.a || test -r $i/$PHP_LIBDIR/$SEARCH_LIB.$SHLIB_SUFFIX_NAME; then
	  MCPP_LIB_DIR=$i/$PHP_LIBDIR
	  AC_MSG_RESULT(mcpp lib found in $i/lib)
    fi
  done

  if test -z "$MCPP_INCLUDE_DIR" || test -z "$mcpp_LIB_DIR"; then
    AC_MSG_RESULT([mcpp not found])
    AC_MSG_ERROR([Please reinstall the mcpp distribution])
  fi

  PHP_ADD_INCLUDE($MCPP_INCLUDE_DIR/include)
  PHP_ADD_LIBRARY_WITH_PATH(mcpp, $MCPP_LIB_DIR, MCPP_SHARED_LIBADD)

  PHP_SUBST(MCPP_SHARED_LIBADD)

  PHP_NEW_EXTENSION(macro, macro.c, $ext_shared)
fi
