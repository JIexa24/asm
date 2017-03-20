
void inline asmSwap(int* a, int* b) {
  asm volatile (".intel_syntax noprefix\n\t"
                "mov eax, %2\n\t"
                "mov %0, %3\n\t"
                "mov %1, eax\n\t"
                : "=r" (*a), "=r"(*b)	
                : "r" (*a), "r"(*b)
                : "%eax"
               );
}
