#include "./../include/asmInline.h"

void asmAtomicAdd(int* result, int num_one, int num_two) {
  asm volatile (
  /*AT&T syntax*/
                "movl %1, %%eax\n\t"
                "movl %2, %%ebx\n\t"
                "addl %%ebx, %%eax\n\t"
                "movl %%eax, %0\n\t"
                : "=m" (*result)
                : "m" (num_one), "m" (num_two)
                : "memory", "%eax", "%ebx"
               );
}
