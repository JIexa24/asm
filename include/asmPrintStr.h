#ifndef ASMPRINTSTR_H
#define ASMPRINTSTR_H

#define asmPrintStrWrite(STR, LEN)   \
  asm volatile (                     \
      "movl $1, %%eax\n\t"           \
      "movl $1, %%ebx\n\t"           \
      "syscall\n\t"                  \
      :                              \
      :"S"(STR), "d"(LEN)            \
      :"%eax", "%ebx"                \
  );

#define asmPrintStrPrintfNoPar(STR)  \
  asm volatile (                     \
      "movl $0, %%eax\n\t"           \
      "call printf\n\t"              \
      :                              \
      :"D"(STR)                      \
      :"%eax", "%ebx"                \
  );
#endif
