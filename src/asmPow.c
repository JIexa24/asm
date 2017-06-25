#include "./../include/asmInline.h"

double asmPowlf(double num, int32_t radix){
  double ret = -1;
  asm volatile (
  /*AT&T syntax*/
                "movq $1, %%rax\n"
                "cmp $0, %%ecx\n\t"
                "jl lowpow%=\n\t"
                "je endpow%=\n"
              "begpow%=:\n\t"
                "cmpl $0, %%ecx\n\t"
                "je endpow%=\n\t"
                "mull %%ebx\n\t"
                "decl %%ecx\n\t"
                "jmp begpow%=\n"
              "lowpow%=:\n\t"
                "movq $0, %%rax\n"
              "endpow%=:\n\t"
                "movq %%rax, %0\n"
                : "=a" (ret)
                : "b" (num), "c" (radix)
                : "memory"
               );
  return ret;
}
/*---------------------------------------------------------------------------*/
int32_t asmPowi(int32_t num, int32_t radix){
  int32_t ret = -1;
  asm volatile (
  /*AT&T syntax*/
                "movl $1, %%eax\n"
                "cmp $0, %%ecx\n\t"
                "jl lowpow%=\n\t"
                "je endpow%=\n"
              "begpow%=:\n\t"
                "cmpl $0, %%ecx\n\t"
                "je endpow%=\n\t"
                "mull %%ebx\n\t"
                "decl %%ecx\n\t"
                "jmp begpow%=\n"
              "lowpow%=:\n\t"
                "movl $0, %%eax\n"
              "endpow%=:\n\t"
                "movl %%eax, %0\n"
                : "=a" (ret)
                : "b" (num), "c" (radix)
                : "memory"
               );
  return ret;
}
/*---------------------------------------------------------------------------*/
float asmPowf(float num, int32_t radix){
  float ret = -1;
  asm volatile (
  /*AT&T syntax*/
                "movl $1, %%eax\n"
                "cmp $0, %%ecx\n\t"
                "jl lowpow%=\n\t"
                "je endpow%=\n"
              "begpow%=:\n\t"
                "cmpl $0, %%ecx\n\t"
                "je endpow%=\n\t"
                "mull %%ebx\n\t"
                "decl %%ecx\n\t"
                "jmp begpow%=\n"
              "lowpow%=:\n\t"
                "movl $0, %%eax\n"
              "endpow%=:\n\t"
                "movl %%eax, %0\n"
                : "=a" (ret)
                : "b" (num), "c" (radix)
                : "memory"
               );
  return ret;
}
/*---------------------------------------------------------------------------*/
int64_t asmPowl(int64_t num, int32_t radix){
  int64_t ret = -1;
  asm volatile (
  /*AT&T syntax*/
                "movq $1, %%rax\n"
                "cmp $0, %%ecx\n\t"
                "jl lowpow%=\n\t"
                "je endpow%=\n"
              "begpow%=:\n\t"
                "cmpl $0, %%ecx\n\t"
                "je endpow%=\n\t"
                "mull %%ebx\n\t"
                "decl %%ecx\n\t"
                "jmp begpow%=\n"
              "lowpow%=:\n\t"
                "movq $0, %%rax\n"
              "endpow%=:\n\t"
                "movq %%rax, %0\n"
                : "=a" (ret)
                : "b" (num), "c" (radix)
                : "memory"
               );
  return ret;
}
