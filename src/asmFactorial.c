#include "./../include/asmInline.h"

int64_t asmFactorial(int64_t num) {
  int64_t ret = -1;
  asm volatile (
  /*AT&T syntax*/
                "movq $1, %%rax\n\t"
              "begfact%=:\n\t"
                "cmpq $0, %%rbx\n\t"
                "je endfact%=\n\t"
                "mulq %%rbx\n\t"
                "decq %%rbx\n\t"
                "jmp begfact%=\n"
              "endfact%=:\n\t"
                "movq %%rax, %0\n"
                : "=m" (ret)
                : "b" (num)
                :
               );
  return ret;
}
