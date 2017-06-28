#include "./../include/asmInline.h"

/*
  if num < 0 return 0;
  if num = 0 return 1;
*/

int64_t asmFactorial(int64_t num) {
  int64_t ret = -1;
  asm volatile (
  /*AT&T syntax*/
                "movq %0, %%rbx\n"
                "movq %1, %%rax\n"
                "movq $1, %%rax\n"
                "cmp $0, %%rbx\n\t"
                "jl lowfact%=\n"
              "begfact%=:\n\t"
                "cmpq $0, %%rbx\n\t"
                "je endfact%=\n\t"
                "mulq %%rbx\n\t"
                "decq %%rbx\n\t"
                "jmp begfact%=\n"
              "lowfact%=:\n\t"
                "movq $0, %%rax\n\t"
              "endfact%=:\n\t"
                "movq %%rax, %0\n"
                : "=r" (ret)
                : "r" (num)
                : "memory", "%rax", "%rbx"
               );
  return ret;
}
