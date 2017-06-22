CC = gcc
CFLAGS = -g3 -O0

all:
	make -C build

asm: ./lib/libAsmInline.a

./lib/libAsmInline.a: ./obj/asmSwap.o ./obj/asmCmp.o
	ar rvs ./lib/asmInline.a ./obj/asmSwap.o ./obj/asmCmp.o

./obj/asmSwap.o: ./src/asmSwap.c
	$(CC) -c ./src/asmSwap.c -o ./obj/asmSwap.o $(CFLAGS)

./obj/asmCmp.o: ./src/asmCmp.c
	$(CC) -c ./src/asmCmp.c -o ./obj/asmCmp.o $(CFLAGS)

clean:
	rm ./obj/*.o
