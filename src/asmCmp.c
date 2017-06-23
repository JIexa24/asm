#include "./../include/asmInline.h"

int asmCmplf(double a, double b) {
  int ret = -2;
  asm volatile (
  /*intel syntax*/
  /*
                ".intel_syntax noprefix\n\t"
                "cmp eax, edx\n\t"
                "jg big\n\t"
                "jl low\n\t"
                "mov %0, 0\n\t"
                "jmp end \n"
              "big:\n\t"
                "mov %0, 1\n\t"
                "jmp end \n"
              "low:\n\t"
                "mov %0, -1\n"
              "end:\n"
  */
  /*AT&T syntax*/
              "cmp %%edx, %%eax\n\t"
              "jg biglf\n\t"
              "jl lowlf\n\t"
              "movl $0, %0\n\t"
              "jmp endlf \n"
            "biglf:\n\t"
              "movl $1, %0\n\t"
              "jmp endlf \n"
            "lowlf:\n\t"
              "movl $(-1), %0\n"
            "endlf:\n"
              : "=m"(ret)
              : "a" (a), "d"(b)
              :
             );
  return ret;
}
/*---------------------------------------------------------------------------*/
int asmCmpi(int32_t a, int32_t b) {
  int ret = -2;
  asm volatile (
  /*AT&T syntax*/
              "cmp %%edx, %%eax\n\t"
              "jg bigi\n\t"
              "jl lowi\n\t"
              "movl $0, %0\n\t"
              "jmp endi \n"
            "bigi:\n\t"
              "movl $1, %0\n\t"
              "jmp endi \n"
            "lowi:\n\t"
              "movl $(-1), %0\n"
            "endi:\n"
              : "=m"(ret)
              : "a" (a), "d"(b)
              :
             );
  return ret;
}

/*---------------------------------------------------------------------------*/
int asmCmpf(float a, float b) {
  int ret = -2;
  asm volatile (
  /*AT&T syntax*/
              "cmp %%edx, %%eax\n\t"
              "jg bigf\n\t"
              "jl lowf\n\t"
              "movl $0, %0\n\t"
              "jmp endf \n"
            "bigf:\n\t"
              "movl $1, %0\n\t"
              "jmp endf \n"
            "lowf:\n\t"
              "movl $(-1), %0\n"
            "endf:\n"
              : "=m"(ret)
              : "a" (a), "d"(b)
              :
             );
  return ret;
}
/*---------------------------------------------------------------------------*/
int asmCmpl(int64_t a, int64_t b) {
  int ret = -2;
  asm volatile (
  /*AT&T syntax*/
              "cmp %%rdx, %%rax\n\t"
              "jg bigl\n\t"
              "jl lowl\n\t"
              "movl $0, %0\n\t"
              "jmp endl \n"
            "bigl:\n\t"
              "movl $1, %0\n\t"
              "jmp endl \n"
            "lowl:\n\t"
              "movl $(-1), %0\n"
            "endl:\n"
              : "=m"(ret)
              : "a" (a), "d"(b)
              :
             );
  return ret;
}
