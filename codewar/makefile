CFLAGS= -Wall -Werror -ansi -pedantic
EXEC=main

all: $(EXEC)

main: main.o init.o displayGrid.o displayCPU.o open_load.o random.o extract.o

main.o: main.c struct.h prototype.h
init.o: init.c struct.h prototype.h
open_load.o: open_load.c struct.h prototype.h
extract.o: extract.c
displayGrid.o: displayGrid.c struct.h prototype.h
displayCPU.o: displayCPU.c struct.h prototype.h
random.o: random.c struct.h prototype.h

clean:
	rm *.o

mrproper: clean
	rm $(EXEC)
