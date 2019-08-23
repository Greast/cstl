
#include "tests.h"

struct cmocka_unit_test_list * CMOCKA_UNIT_TEST_LIST = NULL;


int main(void) {
  const size_t size = LIST_SIZE(CMOCKA_UNIT_TEST_LIST);
  struct CMUnitTest tests[size];
  size_t i = 0;
  for (auto_t l = CMOCKA_UNIT_TEST_LIST ; l && i < size ; l = l->next, ++i) {
    tests[i] = l->data;
  }
  return cmocka_run_group_tests(tests, NULL, NULL);
}
