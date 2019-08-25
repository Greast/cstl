#ifndef __CSTL_EXEPCTION_H_
#define __CSTL_EXEPCTION_H_

#define EXCEPTION(name, tag, value, msg) name {\
  const enum {tag} kind;\
  const value tag;\
  const char * msg;\
}

#endif /* end of include guard: __CSTL_EXEPCTION_H_ */
