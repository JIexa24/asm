CC = gcc
CFLAGS = -g3 -O0

all:
	make -C build

asm: ./lib/libAsmInline.a

./lib/libAsmInline.a: ./obj/asmSwap.o ./obj/asmCmp.o ./obj/asmFactorial.o ./obj/asmPow.o
	ar rvs ./lib/libAsmInline.a ./obj/asmSwap.o ./obj/asmCmp.o ./obj/asmFactorial.o ./obj/asmPow.o

./obj/asmSwap.o: ./src/asmSwap.c
	$(CC) -c ./src/asmSwap.c -o ./obj/asmSwap.o $(CFLAGS)

./obj/asmCmp.o: ./src/asmCmp.c
	$(CC) -c ./src/asmCmp.c -o ./obj/asmCmp.o $(CFLAGS)

./obj/asmFactorial.o: ./src/asmFactorial.c
	$(CC) -c ./src/asmFactorial.c -o ./obj/asmFactorial.o $(CFLAGS)

./obj/asmPow.o: ./src/asmPow.c
	$(CC) -c ./src/asmPow.c -o ./obj/asmPow.o $(CFLAGS)

clean:
	rm ./obj/*.o
