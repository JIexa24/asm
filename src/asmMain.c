#include <stdio.h>
#include "../include/asmInline.h"
#include <string.h>
int main(int argc, char** argv)
{
  float a = 10.6;
  float b = 20.5;
  asmSwap(&a, &b);
  printf("swap - (20.5 10.6) - %f %f\n", a, b);
  printf("cmp - (-1 0 1) -%d %d %d\n",
         asmCmp(10,9),
         asmCmp((float)10.0, 10),
         asmCmp(9,10));

  printf("fact - (120 1 0) - %ld %ld %ld\n",
  asmFactorial(5),
  asmFactorial(0),
  asmFactorial(-2));

  printf("pow - (16 100 4 1 0) - %d %d %d %d %d \n",
  asmPow(2,4), asmPow(100,1), asmPow(2, 2),asmPow(5,0), asmPow(1, -5));

  int a1, b1,c;
  asmAtomicAdd(&a1,2,3);
  asmAtomicAdd(&b1,6,4);
  asmAtomicAdd(&c,0,3);
  emptyAsm();
  printf("Welcome %lf%lf", a, b);
  emptyAsm();
  printf("add - (5 10 3) - %d %d %d\n", a1,b1,c);
  int len = 16;
  char locptr[17] = "HelloAssembler!\n";
  asmPrintStrWrite("HelloAssembler!\n", 16);
  asmPrintStrPrintfNoPar("HelloAssembler!\n");
  return 0;
}
