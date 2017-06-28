#include "./../include/asmInline.h"

void asmSwaplf(double* a, double* b) {
  asm volatile (
  /*AT&T syntax*/
                "movq %0, %%rax\n\t"
                "movq %1, %%rbx\n\t"
                "movq %%rax, %1\n\t"
                "movq %%rbx, %0\n\t"
  /*intel syntax*/
  /*
                ".intel_syntax noprefix\n\t"
                "mov %0, rbx\n\t"
                "mov %1, rax\n\t"
  */
                : "=r" (*a), "=r" (*b)
                : "0" (*a), "1" (*b)
                : "memory", "%rax", "%rbx"
               );
}
/*---------------------------------------------------------------------------*/
void asmSwapi(int32_t* a, int32_t* b) {
  asm volatile (
  /*AT&T syntax*/
                "movl %0, %%eax\n\t"
                "movl %1, %%ebx\n\t"
                "movl %%eax, %1\n\t"
                "movl %%ebx, %0\n\t"
                : "=r" (*a), "=r" (*b)
                : "0" (*a), "1" (*b)
                : "memory", "%eax", "%ebx"
               );
}
/*---------------------------------------------------------------------------*/
void asmSwapf(float* a, float* b) {
  asm volatile (
  /*AT&T syntax*/
                "movl %0, %%eax\n\t"
                "movl %1, %%ebx\n\t"
                "movl %%eax, %1\n\t"
                "movl %%ebx, %0\n\t"
                : "=r" (*a), "=r" (*b)
                : "0" (*a), "1" (*b)
                : "memory", "%eax", "%ebx"
               );
}
/*---------------------------------------------------------------------------*/
void asmSwapl(int64_t* a, int64_t* b) {
  asm volatile (
  /*AT&T syntax*/
                "movq %0, %%rax\n\t"
                "movq %1, %%rbx\n\t"
                "movq %%rax, %1\n\t"
                "movq %%rbx, %0\n\t"
                : "=r" (*a), "=r" (*b)
                : "0" (*a), "1" (*b)
                : "memory", "%rax", "%rbx"
               );
}
