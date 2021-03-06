/*
* Copyright © 2017 Embedded Artistry LLC.
* License: MIT. See LICENSE file for details.
*/

#include <stdlib.h>

// Cmocka needs these
// clang-format off
#include <setjmp.h>
#include <stdarg.h>
#include <stddef.h>
#include <cmocka/cmocka.h>
// clang-format on

#pragma mark - Private Functions -

static void llabs_test(void** state)
{
	assert_int_equal(imaxabs(0), 0);
	assert_int_equal(imaxabs(1), 1);
	assert_int_equal(imaxabs(-1), 1);
	assert_int_equal(imaxabs(LLONG_MAX), LLONG_MAX);
	assert_int_equal(imaxabs(-LLONG_MAX), LLONG_MAX);
	assert_int_equal(imaxabs(LLONG_MIN), LLONG_MIN);
	assert_int_equal(imaxabs(-LLONG_MIN), LLONG_MIN);
}

#pragma mark - Public Functions -

int llabs_tests(void)
{
	const struct CMUnitTest llabs_tests[] = {cmocka_unit_test(llabs_test)};

	return cmocka_run_group_tests(llabs_tests, NULL, NULL);
}
