
/*
  +------------------------------------------------------------------------+
  | Phalcon Framework                                                      |
  +------------------------------------------------------------------------+
  | Copyright (c) 2011-2012 Phalcon Team (http://www.phalconphp.com)       |
  +------------------------------------------------------------------------+
  | This source file is subject to the New BSD License that is bundled     |
  | with this package in the file docs/LICENSE.txt.                        |
  |                                                                        |
  | If you did not receive a copy of the license and are unable to         |
  | obtain it through the world-wide-web, please send an email             |
  | to license@phalconphp.com so we can send you a copy immediately.       |
  +------------------------------------------------------------------------+
  | Authors: Andres Gutierrez <andres@phalconphp.com>                      |
  |          Eduar Carvajal <eduar@phalconphp.com>                         |
  +------------------------------------------------------------------------+
*/

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include "php.h"
#include "php_phalcon.h"
#include "phalcon.h"

#include "Zend/zend_operators.h"
#include "Zend/zend_exceptions.h"
#include "Zend/zend_interfaces.h"

#include "kernel/main.h"
#include "kernel/memory.h"

#include "kernel/object.h"

/**
 * Phalcon\Db\RawValue
 *
 * This class allows to insert/update raw data without quoting or formating.
 *
 *The next example shows how to use the MySQL now() function as a field value.
 *<code>
 *	$subscriber = new Subscribers();
 *	$subscriber->email = 'andres@phalconphp.com';
 *	$subscriber->created_at = new Phalcon\Db\RawValue('now()');
 *	$subscriber->save();
 *</code>
 */

/**
 * Phalcon\Db\RawValue constructor
 *
 * @param string $value
 */
PHP_METHOD(Phalcon_Db_RawValue, __construct){

	zval *value = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &value) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	phalcon_update_property_zval(this_ptr, SL("_value"), value TSRMLS_CC);
	
	PHALCON_MM_RESTORE();
}

/**
 * Returns internal raw value without quoting or formating
 *
 * @return string
 */
PHP_METHOD(Phalcon_Db_RawValue, getValue){

	zval *value = NULL;

	PHALCON_MM_GROW();
	PHALCON_INIT_VAR(value);
	phalcon_read_property(&value, this_ptr, SL("_value"), PH_NOISY_CC);
	
	RETURN_CCTOR(value);
}

/**
 * Magic method __toString returns raw value without quoting or formating
 */
PHP_METHOD(Phalcon_Db_RawValue, __toString){

	zval *value = NULL;

	PHALCON_MM_GROW();
	PHALCON_INIT_VAR(value);
	phalcon_read_property(&value, this_ptr, SL("_value"), PH_NOISY_CC);
	
	RETURN_CCTOR(value);
}

