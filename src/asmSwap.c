#include "./../include/asmInline.h"

void asmSwaplf(double* a, double* b) {
  asm volatile (
  /*AT&T syntax*/
                "movq %%rax, %1\n\t"
                "movq %%rbx, %0\n\t"
  /*intel syntax*/
  /*
                ".intel_syntax noprefix\n\t"
                "mov %0, rbx\n\t"
                "mov %1, rax\n\t"
  */
                : "=m" (*a), "=m"(*b)
                : "b" (*b), "a"(*a)
                :
               );
}
/*---------------------------------------------------------------------------*/
void asmSwapi(int32_t* a, int32_t* b) {
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
void asmSwapl(int64_t* a, int64_t* b) {
  asm volatile (
  /*AT&T syntax*/
                "movq %%rax, %1\n\t"
                "movq %%rbx, %0\n\t"
                : "=m" (*a), "=m"(*b)
                : "b" (*b), "a"(*a)
                :
               );
}
