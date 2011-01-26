CFLAGS= -Wall -Werror -ansi -pedantic
EXEC=main

all: $(EXEC)

main: main.o displayGrid.o displayCPU.o open.o

main.o: main.c struct.h
open.o: open.c
displayGrid.o: displayGrid.c struct.h
displayCPU.o: displayCPU.c struct.h

clean:
	rm *.o

mrproper: clean
	rm $(EXEC)
