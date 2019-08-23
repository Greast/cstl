#ifndef __CSTL_TESTS_MACRO_H_
#define __CSTL_TESTS_MACRO_H_
#include <stdarg.h>
#include <stddef.h>
#include <setjmp.h>
#include <cmocka.h>
#include "cstl/cstl.h"
struct LIST_HEAD(cmocka_unit_test_list, CMUnitTest);

extern struct cmocka_unit_test_list * CMOCKA_UNIT_TEST_LIST;

#define TEST_FUNCTION(name, state) \
  static void name(void **); \
  __attribute__((constructor)) \
  static void name ## _init(){ \
    LIST_ADD(&CMOCKA_UNIT_TEST_LIST, cmocka_unit_test(name)); \
  } \
  static void name(void ** state)

#endif /* end of include guard: __TESTS_MACRO __CSTL__H_*/
