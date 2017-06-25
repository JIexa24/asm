#ifndef ASMPOW_H
#define ASMPOW_H

#include <inttypes.h>

double asmPowlf(double num, int32_t radix);
int32_t asmPowi(int32_t num, int32_t radix);
float asmPowf(float num, int32_t radix);
int64_t asmPowl(int64_t num, int32_t radix);

#define asmPow(x, y) _Generic((x), default: asmPowlf, int32_t: asmPowi, \
                              float: asmPowf, int64_t: asmPowl)(x, y)

#endif
