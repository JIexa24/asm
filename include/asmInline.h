#ifndef ASMINLINE_H
#define ASMINLINE_H

#include <inttypes.h>

/*----------------------------asmSwap-----------------------------------------*/
void asmSwapi(int32_t* a, int32_t* b);
void asmSwapf(float* a, float* b);
void asmSwaplf(double* a, double* b);
void asmSwapl(int64_t* a, int64_t* b);

#define asmSwap(x, y) _Generic((x), default: asmSwaplf, int32_t*: asmSwapi, \
                              float*: asmSwapf, int64_t*: asmSwapl)(x, y)
/*----------------------------asmCmp------------------------------------------*/
int asmCmpi(int32_t a, int32_t b);
int asmCmpf(float a, float b);
int asmCmplf(double a, double b);
int asmCmpl(int64_t a, int64_t b);

#define asmCmp(x, y) _Generic((x), default: asmCmplf, int32_t: asmCmpi, \
                              float: asmCmpf, int64_t: asmCmpl)(x, y)
/*----------------------------asmFactorial------------------------------------*/
int64_t asmFactorial(int64_t num);
/*----------------------------asmPow------------------------------------------*/
double asmPowlf(double num, int32_t radix);
int32_t asmPowi(int32_t num, int32_t radix);
float asmPowf(float num, int32_t radix);
int64_t asmPowl(int64_t num, int32_t radix);

#define asmPow(x, y) _Generic((x), default: asmPowlf, int32_t: asmPowi, \
                              float: asmPowf, int64_t: asmPowl)(x, y)
/*----------------------------asmAtomic---------------------------------------*/
void asmAtomicAdd(int* result, int num_one, int num_two);
/*----------------------------asmPrintStr-------------------------------------*/
#define asmPrintStrWrite(STR, LEN)   \
  asm volatile (                     \
      "movl $1, %%eax\n\t"           \
      "movl $1, %%ebx\n\t"           \
      "syscall\n\t"                  \
      :                              \
      :"S"(STR), "d"(LEN)            \
      :"%eax", "%ebx"                \
  )

#define asmPrintStrPrintfNoPar(STR)  \
  asm volatile (                     \
      "movl $0, %%eax\n\t"           \
      "call printf\n\t"              \
      :                              \
      :"D"(STR)                      \
      :"%eax", "%ebx"                \
  )
/*----------------------------asmStrlen---------------------------------------*/
/*----------------------------asmOther----------------------------------------*/
#define mem_barrier() asm volatile ("":::"memory")
#define emptyAsm() asm volatile ("\n\t":::)

#endif
