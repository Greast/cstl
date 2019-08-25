#include "tests.h"

TEST_FUNCTION(list_add_one_element, _){
  struct LIST(list_int, int) * list = NULL;
  LIST_ADD(&list, 0);
  assert_non_null(list);
  assert_int_equal(list->data, 0);
}

TEST_FUNCTION(list_add_two_elements, _){
  struct LIST(list_int, int) * list = NULL;
  LIST_ADD(&list, 0);
  LIST_ADD(&list, 1);
  assert_non_null(list);
  assert_int_equal(list->data, 1);
  assert_int_equal(list->next->data, 0);
}


TEST_FUNCTION(list_add_multiple_element, _){
  struct LIST(list_int, int) * list = NULL;
  const size_t count = 100;
  size_t i = 0;
  for(;i < count; ++i) {
    LIST_ADD(&list, i);
    assert_non_null(list);
  }
  for(;i < count; --i, list = list ->next){
    assert_int_equal(list->data, i);
  }
}
