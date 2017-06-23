#ifndef ASMCMP_H
#define ASMCMP_H

#include <inttypes.h>

int asmCmpi(int32_t a, int32_t b);
int asmCmpf(float a, float b);
int asmCmplf(double a, double b);
int asmCmpl(int64_t a, int64_t b);

#define asmCmp(x, y) _Generic((x), default: asmCmplf, int32_t: asmCmpi, \
                              float: asmCmpf, int64_t: asmCmpl)(x, y)

#endif
