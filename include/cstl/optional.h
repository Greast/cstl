#ifndef __CSTL_OPTIONAL_H_
#define __CSTL_OPTIONAL_H_

struct None{};

#define OPTIONAL(name, value) name {\
  const enum {OPTIONAL_some, OPTIONAL_none} kind; \
  union{ \
    value OPTIONAL_some; \
    struct None OPTIONAL_none; \
  }data; \
}

#define OPTIONAL_SOME(some_value) {\
  .kind = OPTIONAL_some,\
  .data.value = some_value\
}

#define OPTIONAL_NONE(){\
  .kind = OPTIONAL_none\
}
#endif /* end of include guard: __CSTL_OPTIONAL_H_ */
