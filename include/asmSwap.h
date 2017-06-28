#ifndef ASMSWAP_H
#define ASMSWAP_H

#include <inttypes.h>

void asmSwapi(int32_t* a, int32_t* b);
void asmSwapf(float* a, float* b);
void asmSwaplf(double* a, double* b);
void asmSwapl(int64_t* a, int64_t* b);

#define asmSwap(x, y) _Generic((x), default: asmSwaplf, int32_t*: asmSwapi, \
                              float*: asmSwapf, int64_t*: asmSwapl)(x, y)
#endif
