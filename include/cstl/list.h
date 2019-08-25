#ifndef __CTSL_LIST_H_
#define __CTSL_LIST_H_
#include "cstl/alloc.h"
#include "cstl/optional.h"
#define LIST(name, inner) name { \
  struct name * next; \
  inner data;\
}

#define LIST_ADD(variable, element) ({ \
  typeof(**variable) var; \
  var.next = (*(variable)); \
  var.data = (typeof(var.data)) element;\
  *variable = HEAPIFY(var);\
  variable; \
})

#define LIST_SIZE(list) ({\
  size_t i = 0;\
  for(auto_t l = list ; l ; l = l -> next, ++i);\
  i;\
})

#define LIST_REVERSE(list)({\
  auto_t next = *list;\
  typeof(next) * old = NULL;\
  while (next) {\
    *list = next;\
    next = (*list)->next;\
    (*list)-> next = old;\
    old = *list;\
  }\
  *list;\
})

#define LIST_FROM_ARRAY(array, size) ({\
  struct LIST_HEAD(list, {typeof(*array) value;}) list; \
  for (size_t i = size -1 ; i < size ; --i ) { \
    LIST_ADD(&list, array[i]) \
  } \
  list;\
})

#define LIST_CMP(lhs, rhs, function)({\
  while(lhs & rhs){\
    const int ret = function(&lhs->data, &rhs->data);\
    lhs = lhs->next;\
    rhs = rhs->next;\
  }\
  return lhs - rhs;\
})

#define LIST_GET(list, index)({\
  struct OPTIONAL(list_get_optional, typeof(list));\
  for (auto_t l = list ; l && index ; l = l ->next ; --index ) ;\
  if(l) {\
    list_get_optional ret = OPTIONAL_SOME(l->data);\
    return ret;\
  } else {\
    list_get_optional ret = OPTIONAL_NONE();\
    return ret;\
  }\
})


#endif /* end of include guard: __CTSL_LIST_H_ */
