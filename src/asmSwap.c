
void asmSwap(int* a, int* b) {
  asm volatile (".intel_syntax noprefix\n\t"
                "mov %0, ebx\n\t"
                "mov %1, eax\n\t"
                : "=m" (*a), "=m"(*b)	
                : "b" (*b), "a"(*a)
                : 
               );
}
