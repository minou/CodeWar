CFLAGS= -Wall -Werror -ansi -pedantic
EXEC=main
all: $(EXEC)

main: main.o init.o displayGrid.o displayCPU.o open_load.o random.o extract.o execute.o shell.o ligne_commande.o
	gcc -o $@ $^

makefile.dep: Makefile $(wildcard *.[ch])
	gcc -MM *.c > $@

include makefile.dep

clean:
	rm *.o

mrproper: clean
	rm $(EXEC)
	rm makefile.dep
