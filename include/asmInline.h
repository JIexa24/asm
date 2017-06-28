#ifndef ASMINLINE_H
#define ASMINLINE_H

#include "asmSwap.h"
#include "asmCmp.h"
#include "asmStrlen.h"
#include "asmFactorial.h"
#include "asmPow.h"
#include "asmAtomic.h"

#define mem_barrier() asm volatile ("":::"memory")

#endif
