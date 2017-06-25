#include <stdio.h>
#include "../include/asmInline.h"

int main(int argc, char** argv)
{
  int a = 10;
  int b = 20;
  asmSwapi(&a, &b);
  printf("swap - (20 10) - %d %d\n", a, b);
  printf("cmp - (-1 0 1) -%d %d %d\n",
         asmCmp(10,9),
         asmCmp((float)10.0, 10),
         asmCmp(9,10));

  printf("fact - (120 1 0) - %ld %ld %ld\n",
  asmFactorial(5),
  asmFactorial(0),
  asmFactorial(-2));

  printf("pow - (16 100 2.25 1 0) - %ld %ld %lf %ld %ld \n",
  asmPow(2,4), asmPow(100,1), asmPow(1.5, 2),asmPow(5,0), asmPow(1, -5));
  return 0;
}
