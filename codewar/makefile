CFLAGS= -Wall -Werror -ansi -pedantic
EXEC=main

all: $(EXEC)

main: main.o init.o open_load.o displayGrid.o displayCPU.o

main.o: main.c struct.h
init.o: init.c struct.h
open_load.o: open_load.c struct.h
displayGrid.o: displayGrid.c struct.h
displayCPU.o: displayCPU.c struct.h

clean:
	rm *.o

mrproper: clean
	rm $(EXEC)
