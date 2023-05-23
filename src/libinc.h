#ifndef LIBHEADER_H
#define LIBHEADER_H

#include <stdint.h>
#include <stdbool.h>

#ifdef LS_USERDIEFUNC
  #define SPANDIE LS_USERDIEFUNC
#else
  #define SPANDIE *(volatile int *)0 = 0
#endif

#define TSPAN(T) typedef struct {T* ptr;int32_t len;} T##Span; \
  static inline T T##Span##Get(T##Span sp, int32_t idx) { if(idx < 0 || idx >= sp.len) SPANDIE; return sp.ptr[idx];} \
  static inline void T##Span##Set(T##Span sp, int32_t idx, T value) { if(idx < 0 || idx >= sp.len) SPANDIE; sp.ptr[idx] = value;} \


TSPAN(bool);
TSPAN(uint8_t);
TSPAN(int8_t);
TSPAN(char);
TSPAN(double);
TSPAN(float);
TSPAN(int32_t);
TSPAN(uint32_t);
TSPAN(int_least16_t);
TSPAN(uint_least16_t);
TSPAN(int64_t);
TSPAN(uint64_t);
TSPAN(int16_t);
TSPAN(uint16_t);

#undef TSPAN
#undef SPANDIE

#endif
