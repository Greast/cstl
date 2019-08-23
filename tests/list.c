#include "tests.h"

TEST_FUNCTION(list_add_single_element, _){
  struct LIST_HEAD(list_int, {
    int value;
  }) * list = NULL;
  LIST_ADD(&list, {.value = 0});
  assert_non_null(list);
  assert_int_equal(list->data.value, 0);
}


TEST_FUNCTION(list_add_multiple_element, _){
  struct LIST_HEAD(list_int, {
    int value;
  }) * list = NULL;
  const size_t count = 100;
  size_t i = 0;
  for(;i < count; ++i) {
    LIST_ADD(&list, {.value = 0});
    assert_non_null(list);
  }
  for(;i < count; --i, list = list ->next){
    assert_int_equal(list->data.value, i);
  }
}
