#ifndef LIBHEADER_H
#define LIBHEADER_H

#include <stdint.h>
#include <stdbool.h>

#ifdef __STDC_HOSTED__
#include <stdio.h>
#define PERR(msg) fprintf(stderr, "ERROR: %s:%d in %s: %s\n", __FILE__, __LINE__, __func__, (msg))
#else
#define PERR(msg)
#endif

#ifdef LS_USERDIEFUNC
  #define TRAP(msg) LS_USERDIEFUNC(msg) 
#else
#if __GNUC__
      #define TRAP(msg) {PERR(msg); __builtin_trap();}
#elif _MSC_VER
      #define TRAP(msg) {PERR(msg); __debugbreak();}
#else
      #define TRAP(msg) {PERR(msg); *(volatile int *)0 = 0;}
#endif
#endif

#define TRAPI TRAP("Index outside array or slice boundary");

#ifdef NDEBUG
#define assert(cond) ((void)(cond))
#else
#define assert(cond) if(!(cond)) {TRAP("assert triggered -> '" #cond "'");}
#endif

#define tassert(cond) if(!(cond)) {TRAP("'" #cond "'");}

#define SPANGET(sp,idx)        ({ if(idx < 0 || idx >= sp.len) TRAPI; sp.ptr[idx];})
#define SPANSET(sp,idx, value) ({ if(idx < 0 || idx >= sp.len) TRAPI; sp.ptr[idx] = value;})
#define SPANSLICE(sp,s,e)      ({ if(s < 0 || e >= sp.len || e < s) TRAPI; (typeof(sp)){ &sp.ptr[s], e - s + 1 }; })
#define SPANARR(sp,arr,s,e)    ({ if(s < 0 || e >= ARSIZE(arr) || e < s) TRAPI; (typeof(sp)) tmp = { &arr[s], e - s + 1 }; tmp; })

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

#define CharSpanFromLit(lit) (charSpan) { lit, sizeof(lit) - 1}

#undef TSPAN
#undef SPANDIE

#define ARSIZE(arr) (sizeof(arr)/sizeof(0[arr]))

#endif
