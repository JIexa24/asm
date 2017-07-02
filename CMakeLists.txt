cmake_minimum_required(VERSION 2.8)
project(Asm)

include_directories(include)

set(SOURCE_LIB src/asmCmp.c src/asmSwap.c src/asmFactorial.c src/asmPow.c src/asmAtomic.c src/asmPrintStr.c)

add_library(AsmInline STATIC ${SOURCE_LIB})

add_executable(../bin/asm src/asmMain.c)
target_link_libraries(../bin/asm AsmInline)
