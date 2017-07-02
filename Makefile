CC = gcc
CFLAGS = -g3 -O0 --save-temps

all:
	make -C build

asm: ./lib/libAsmInline.a

./lib/libAsmInline.a: ./obj/asmSwap.o ./obj/asmCmp.o ./obj/asmFactorial.o ./obj/asmPow.o ./obj/asmAtomic.o
	ar rvs ./lib/libAsmInline.a ./obj/asmSwap.o ./obj/asmCmp.o ./obj/asmFactorial.o ./obj/asmPow.o ./obj/asmAtomic.o  

mainbin:
	$(CC) ./src/asmMain.c ./src/asmSwap.c ./src/asmCmp.c ./src/asmFactorial.c ./src/asmPow.c ./src/asmAtomic.c  -o ./bin/asm $(CFLAGS)

./obj/asmSwap.o: ./src/asmSwap.c
	$(CC) -c ./src/asmSwap.c -o ./obj/asmSwap.o $(CFLAGS)

./obj/asmCmp.o: ./src/asmCmp.c
	$(CC) -c ./src/asmCmp.c -o ./obj/asmCmp.o $(CFLAGS)

./obj/asmFactorial.o: ./src/asmFactorial.c
	$(CC) -c ./src/asmFactorial.c -o ./obj/asmFactorial.o $(CFLAGS)

./obj/asmPow.o: ./src/asmPow.c
	$(CC) -c ./src/asmPow.c -o ./obj/asmPow.o $(CFLAGS)

./obj/asmAtomic.o: ./src/asmAtomic.c
	$(CC) -c ./src/asmAtomic.c -o ./obj/asmAtomic.o $(CFLAGS)

clean:
	rm ./obj/*.o
