#include "./../include/asmInline.h"

void asmSwapInt(int* a, int* b) {
  asm volatile (
                ".intel_syntax noprefix\n\t"
                "mov %0, ebx\n\t"
                "mov %1, eax\n\t"
  /* AT&T synatax
                "mov %%eax, %1\n\t"
                "mov %%ebx, %0\n\t"
   */
                : "=m" (*a), "=m"(*b)
                : "b" (*b), "a"(*a)
                :
               );
}
