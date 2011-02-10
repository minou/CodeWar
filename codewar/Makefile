CFLAGS= -Wall -Werror -ansi -pedantic
EXEC=../bin/main ../bin/shell
all: $(EXEC)

../bin/shell: shell.o conversion.o
	gcc -o $@ $^
../bin/main: main.o init.o displayGrid.o displayCPU.o open_load.o random.o extract.o conversion.o execute.o
	gcc -o $@ $^

makefile.dep: Makefile $(wildcard *.[ch])
	gcc -MM *.c > $@

include makefile.dep

clean:
	rm *.o

mrproper: clean
	rm $(EXEC)
	rm makefile.dep
