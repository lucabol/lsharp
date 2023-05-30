#ifndef LIBHEADER_H
#define LIBHEADER_H

#include <stdint.h>
#include <stdbool.h>

#ifdef LS_USERDIEFUNC
  #define TRAP LS_USERDIEFUNC
#else
#if __GNUC__
      #define TRAP __builtin_trap()
#elif _MSC_VER
      #define TRAP __debugbreak()
#else
      #define TRAP *(volatile int *)0 = 0
#endif
#endif

#define TSPAN(T) typedef struct {T* ptr;int32_t len;} T##Span; \
  static inline T T##SpanGet(T##Span sp, int32_t idx) { if(idx < 0 || idx >= sp.len) TRAP; return sp.ptr[idx];} \
  static inline void T##SpanSet(T##Span sp, int32_t idx, T value) { if(idx < 0 || idx >= sp.len) TRAP; sp.ptr[idx] = value;} \

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

#define ARSIZE(arr) (sizeof(arr)/sizeof(0[arr]))

#endif
