#include "./../include/asmInline.h"

void asmSwaplf(double* a, double* b) {
  asm volatile (
  /*AT&T syntax*/
                "movl %%eax, %1\n\t"
                "movl %%ebx, %0\n\t"
  /*intel syntax*/
  /*
                ".intel_syntax noprefix\n\t"
                "mov %0, ebx\n\t"
                "mov %1, eax\n\t"
  */
                : "=m" (*a), "=m"(*b)
                : "b" (*b), "a"(*a)
                :
               );
}
/*---------------------------------------------------------------------------*/
void asmSwapi(int* a, int* b) {
  asm volatile (
  /*AT&T syntax*/
                "movl %%eax, %1\n\t"
                "movl %%ebx, %0\n\t"
                : "=m" (*a), "=m"(*b)
                : "b" (*b), "a"(*a)
                :
               );
}
/*---------------------------------------------------------------------------*/
void asmSwapf(float* a, float* b) {
  asm volatile (
  /*AT&T syntax*/
                "movl %%eax, %1\n\t"
                "movl %%ebx, %0\n\t"
                : "=m" (*a), "=m"(*b)
                : "b" (*b), "a"(*a)
                :
               );
}
/*---------------------------------------------------------------------------*/
void asmSwapl(long int* a, long int* b) {
  asm volatile (
  /*AT&T syntax*/
                "movl %%eax, %1\n\t"
                "movl %%ebx, %0\n\t"
                : "=m" (*a), "=m"(*b)
                : "b" (*b), "a"(*a)
                :
               );
}
