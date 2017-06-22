#include <stdio.h>
#include "../include/asmInline.h"

int main(int argc, char** argv)
{
  int a = 10;
  int b = 20;
  asmSwapi(&a, &b);
  printf("%d %d\n", a, b);
  printf("%d %d %d\n",
         asmCmp(10,9),
         asmCmp(10,10),
         asmCmp(9,10));
}
