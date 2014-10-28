dnl $Id$
dnl config.m4 for extension macro

PHP_ARG_WITH(macro, for macro support,
[  --enable-macro             Enable macro support])

if test "$PHP_MACRO" != "no"; then

  PHP_EXT_EMBED_NEW_EXTENSION(macro, macro.c, $ext_shared)
fi
