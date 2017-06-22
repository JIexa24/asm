#ifndef ASMCMP_H
#define ASMCMP_H

int asmCmpi(int a, int b);
int asmCmpf(float a, float b);
int asmCmplf(double a, double b);
int asmCmpl(long int a, long int b);

#define asmCmp(x, y) _Generic((x), default: asmCmplf, int: asmCmpi, \
                              float: asmCmpf, long int: asmCmpl)(x, y)

#endif
