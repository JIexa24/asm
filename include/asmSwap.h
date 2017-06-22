#ifndef ASMSWAP_H
#define ASMSWAP_H

void asmSwapi(int* a, int* b);
void asmSwapf(float* a, float* b);
void asmSwaplf(double* a, double* b);
void asmSwapl(long int* a, long int* b);

#define asmSwap(x, y) _Generic((x), default: asmCmplf, int*: asmCmpi, \
                              float*: asmCmpf, long int*: asmCmpl)(x, y)
#endif
