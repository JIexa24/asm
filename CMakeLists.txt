cmake_minimum_required(VERSION 2.8)
project(Asm)

include_directories(include)

set(SOURCE_LIB src/asmCmp.c src/asmSwap.c src/asmFactorial.c src/asmPow.c)

add_library(AsmInline STATIC ${SOURCE_LIB})
