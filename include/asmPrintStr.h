#ifndef ASMPRINTSTR_H
#define ASMPRINTSTR_H

#define asmPrintStr(STR, LEN)   \
  asm volatile (                \
      "movl $1, %%eax;\n\t"     \
      "movl $1, %%ebx;\n\t"     \
      "syscall;\n\t"            \
      :                         \
      :"S"(STR), "d"(LEN)       \
      :"%eax", "%ebx"           \
  );

#endif
