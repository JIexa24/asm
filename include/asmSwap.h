#ifndef ASMSWAP_H
#define ASMSWAP_H

#include <inttypes.h>

void asmSwapi(int32_t* a, int32_t* b);
void asmSwapf(float* a, float* b);
void asmSwaplf(double* a, double* b);
void asmSwapl(int64_t* a, int64_t* b);

#define asmSwap(x, y) _Generic((x), default: asmCmplf, int32_t*: asmCmpi, \
                              float*: asmCmpf, int64_t*: asmCmpl)(x, y)
#endif
