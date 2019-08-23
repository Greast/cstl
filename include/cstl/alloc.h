#ifndef __CST_ALLOC_H_
#define __CST_ALLOC_H_
#include <stdlib.h>

void * smemcpy(void * destination, const void * source, const size_t size);

#define HEAPIFY(variable) smemcpy(malloc(sizeof(variable)), &variable, sizeof(variable))

#endif /* end of include guard: __CST_ALLOC_H_ */
