--TEST--
Basic
--FILE--
<?php

var_dump(function_exists('macro_preprocess'));
var_dump(ini_get('macro.enable'));
var_dump(defined('PHP_MACRO_VERSION'));
?>
--EXPECT--
bool(true)
bool(true)
bool(true)
