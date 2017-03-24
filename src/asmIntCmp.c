
int asmIntCmp(int a, int b) {
  int ret = -2;

  asm volatile (".intel_syntax noprefix\n\t"
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
                : "=m"(ret)
                : "a" (a), "d"(b)
                :
               );
  return ret;
}
