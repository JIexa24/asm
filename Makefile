CC = gcc
CFLAGS = -g3 -masm=intel -O0

all: asm

asm: ./lib/libAsmInline.a

./lib/libAsmInline.a: ./obj/asmSwap.o ./obj/asmIntCmp.o
	ar rvs ./lib/asmInline.a ./obj/asmSwap.o ./obj/asmIntCmp.o

./obj/asmSwap.o: ./src/asmSwap.c
	$(CC) -c ./src/asmSwap.c -o ./obj/asmSwap.o $(CFLAGS)

./obj/asmIntCmp.o: ./src/asmIntCmp.c
	$(CC) -c ./src/asmIntCmp.c -o ./obj/asmIntCmp.o $(CFLAGS)

clean:
	rm ./obj/*.o
