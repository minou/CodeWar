CFLAGS= -Wall -Werror -ansi -pedantic
EXEC=cw
all: $(EXEC)

cw: main.o init.o displayGrid.o displayCPU.o open_load.o random.o extract.o execute.o shell.o instruction.o
	gcc -o $@ $^

makefile.dep: Makefile $(wildcard *.[ch])
	gcc -MM *.c > $@

include makefile.dep

clean:
	rm *.o
	rm history

mrproper: clean
	rm $(EXEC)
	rm makefile.dep
