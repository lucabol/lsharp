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

#define SPANGET(sp,idx)        ({ if(idx < 0 || idx >= sp.len) TRAP; sp.ptr[idx];})
#define SPANSET(sp,idx, value) ({ if(idx < 0 || idx >= sp.len) TRAP; sp.ptr[idx] = value;})
#define SPANSLICE(sp,s,e)      ({ if(s < 0 || e >= sp.len || e < s) TRAP; (typeof(sp)){ &sp.ptr[s], e - s + 1 }; })
#define SPANARR(sp,arr,s,e)    ({ if(s < 0 || e >= ARSIZE(arr) || e < s) TRAP; (typeof(sp)){ &arr[s], e - s + 1 }; })

#define TSPAN(T) typedef struct {T* ptr;int32_t len;} T##Span;

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

#define String charSpan
TSPAN(String);

static inline charSpan CharSpanFromLit(char* lit) {
  int32_t i = 0;
  while(lit[i++] !=0) ;
  return (charSpan) { lit, i - 1 };
}

#undef TSPAN
#undef SPANDIE

#define ARSIZE(arr) (sizeof(arr)/sizeof(0[arr]))

#endif
