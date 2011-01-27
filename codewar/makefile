CFLAGS= -Wall -Werror -ansi -pedantic
EXEC=main

all: $(EXEC)

main: main.o open.o load.o displayGrid.o displayCPU.o

main.o: main.c struct.h
open.o: open.c
load.o: load.c
displayGrid.o: displayGrid.c struct.h
displayCPU.o: displayCPU.c struct.h

clean:
	rm *.o

mrproper: clean
	rm $(EXEC)
