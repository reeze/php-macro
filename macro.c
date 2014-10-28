/*
  +----------------------------------------------------------------------+
  | PHP Version 5                                                        |
  +----------------------------------------------------------------------+
  | Copyright (c) 1997-2012 The PHP Group                                |
  +----------------------------------------------------------------------+
  | This source file is subject to version 3.01 of the PHP license,      |
  | that is bundled with this package in the file LICENSE, and is        |
  | available through the world-wide-web at the following url:           |
  | http://www.php.net/license/3_01.txt                                  |
  | If you did not receive a copy of the PHP license and are unable to   |
  | obtain it through the world-wide-web, please send a note to          |
  | license@php.net so we can mail you a copy immediately.               |
  +----------------------------------------------------------------------+
  | Author: Reeze Xia <reeze@php.net>                                    |
  +----------------------------------------------------------------------+
*/

/* $Id$ */

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include "php.h"
#include "main/php_ini.h"
#include "ext/standard/info.h"

#include "php_macro.h"


#ifndef PHP_FE_END
# define PHP_FE_END { NULL, NULL, NULL, 0, 0 }
#endif

#if ZEND_MODULE_API_NO < 20090626
# define Z_ADDREF_P(arg) ZVAL_ADDREF(arg)
# define Z_ADDREF_PP(arg) ZVAL_ADDREF(*(arg))
# define Z_DELREF_P(arg) ZVAL_DELREF(arg)
# define Z_DELREF_PP(arg) ZVAL_DELREF(*(arg))
#endif

#ifndef zend_parse_parameters_none
# define zend_parse_parameters_none() zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "")
#endif

ZEND_DECLARE_MODULE_GLOBALS(macro)

/* {{{ PHP_INI */
PHP_INI_BEGIN()
	STD_PHP_INI_BOOLEAN("macro.active",	"1",	PHP_INI_SYSTEM,		OnUpdateBool,		active,	zend_macro_globals,		macro_globals)
PHP_INI_END()
/* }}} */


PHP_FUNCTION(macro_preprocess)
{
	char *code;
	int code_len;

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "s",
		&code, &code_len) == FAILURE) {
		return;
	}

	// TODO implement it
	RETVAL_STRINGL(code, code_len, 1);
}

/* {{{ PHP_MINIT_FUNCTION
 */
PHP_MINIT_FUNCTION(macro)
{
	/* Register constants */
	REGISTER_STRING_CONSTANT("PHP_MACRO_VERSION", PHP_MACRO_VERSION, CONST_CS | CONST_PERSISTENT);

	REGISTER_INI_ENTRIES();

	return SUCCESS;
}
/* }}} */

/* {{{ PHP_MSHUTDOWN_FUNCTION
 */
PHP_MSHUTDOWN_FUNCTION(macro)
{
       return SUCCESS;
}
/* }}} */

/* {{{ PHP_MINFO_FUNCTION
 */
PHP_MINFO_FUNCTION(macro)
{
	php_info_print_table_start();
	php_info_print_table_header(2, "macro support", "enabled");
	php_info_print_table_header(2, "macro active", MACRO_G(active) ? "yes" : "no");
	php_info_print_table_end();
}
/* }}} */

ZEND_BEGIN_ARG_INFO_EX(arginfo_macro_preprocess, 0, 0, 1)
	ZEND_ARG_INFO(0, code)
ZEND_END_ARG_INFO()

/* {{{ macro_functions[]
 */
const zend_function_entry macro_functions[] = {
	PHP_FE(macro_preprocess, arginfo_macro_preprocess)
	PHP_FE_END	/* Must be the last line in macro_functions[] */
};
/* }}} */

/* {{{ macro_module_entry
 */
zend_module_entry macro_module_entry = {
#if ZEND_MODULE_API_NO >= 20010901
	STANDARD_MODULE_HEADER,
#endif
	"macro",
	macro_functions,
	PHP_MINIT(macro),
	PHP_MSHUTDOWN(macro),
	NULL,
	NULL,
	PHP_MINFO(macro),
#if ZEND_MODULE_API_NO >= 20010901
	PHP_MACRO_VERSION,
#endif
	STANDARD_MODULE_PROPERTIES
};
/* }}} */

#ifdef COMPILE_DL_MACRO
ZEND_GET_MODULE(macro)
#endif

/*
 * Local variables:
 * tab-width: 4
 * c-basic-offset: 4
 * End:
 * vim600: noet sw=4 ts=4 fdm=marker
 * vim<600: noet sw=4 ts=4
 */
