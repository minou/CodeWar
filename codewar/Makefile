CFLAGS= -Wall -Werror -ansi -pedantic
EXEC=main shell
all: $(EXEC)

shell: shell.o conversion.o
	gcc -o $@ $^
main: main.o init.o displayGrid.o displayCPU.o open_load.o random.o extract.o conversion.o execute.o
	gcc -o $@ $^

makefile.dep: Makefile $(wildcard *.[ch])
	gcc -MM *.c > $@

include makefile.dep

clean:
	rm *.o

mrproper: clean
	rm $(EXEC)
	rm makefile.dep
