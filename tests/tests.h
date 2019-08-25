#ifndef __CSTL_TESTS_MACRO_H_
#define __CSTL_TESTS_MACRO_H_
#include <stdarg.h>
#include <stddef.h>
#include <setjmp.h>
#include <cmocka.h>
#include <stdio.h>
#include "cstl/cstl.h"

struct LIST(cmocka_unit_test_list, struct CMUnitTest);

extern struct cmocka_unit_test_list * CMOCKA_UNIT_TEST_LIST;

#define TEST_FUNCTION(function_name, state) \
  static void function_name(void **); \
  __attribute__((constructor)) \
  static void function_name ## _init(){ \
    LIST_ADD(&CMOCKA_UNIT_TEST_LIST, cmocka_unit_test(function_name)); \
  } \
  static void function_name(void ** state)

#endif /* end of include guard: __TESTS_MACRO __CSTL__H_*/
