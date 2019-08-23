#ifndef __CSTL_STRING_H_
#define __CSTL_STRING_H_
#include <stdio.h>
#include <string.h>
#define FORMAT(stream_name, ...)({\
  char *buf = NULL;\
  size_t len = 0;\
  FILE* stream_name = open_memstream(&buf, &len);\
  {...}\
  fclose(stream_name);\
  buf;\
})

#endif /* end of include guard: __CSTL_STRING_H_ */
