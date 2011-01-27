#include "struct.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

int main(int args , char ** argv)
{
    char * option = argv[1];

    CPU grid[NB_CPU];
    unsigned char ** stock_hexa = malloc(15 * sizeof(unsigned char *));

    if (option == NULL){
        printf("%s\n", "Usage: ./main -option");
        return -1;
    }
    
    /* Display grid */
    if (strcmp(option, "-g") == 0){
        display_grid(grid);
    }

    /* Display CPU */
    if (strcmp(option, "-c") == 0){
        setMem();
        displayCPU();
        setReg();
        displayReg();
    }

    /* Open and load program in CPU */
    if (strcmp(option, "-f") == 0){
        openFile(argv[2], stock_hexa);
    }

    return 0;
}
