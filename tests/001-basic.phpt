--TEST--
Basic
--INI--
macro.active=1
--FILE--
<?php

var_dump(function_exists('macro_preprocess'));
var_dump(ini_get('macro.active'));
var_dump(defined('PHP_MACRO_VERSION'));
?>
--EXPECT--
bool(true)
string(1) "1"
bool(true)
