#include "cstl/alloc.h"
#include <string.h>
void * smemcpy(void * destination, const void * source, const size_t size){
  if(!destination | !source) return NULL;
  return memcpy(destination, source, size);
}
