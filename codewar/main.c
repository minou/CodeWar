#include "struct.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

int main(int args , char ** argv)
{
    char * option;

    CPU  * grid = malloc(NB_CPU * sizeof(CPU *));

    /*unsigned char ** stock_hexa = malloc(15 * sizeof(unsigned char *));*/

    init(grid);

    option = argv[1];
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
        int nb;
        if (argv[2] == NULL){
            return -1;
        }
        nb = atoi(argv[2]);
        if (nb < 0 || nb >= NB_CPU){
            return -1;
        }
        displayCPU(grid[nb]);
        displayReg(grid[nb]);
    }

    /* Open and load program in CPU */
    if (strcmp(option, "-f") == 0){
        /*openFile(argv[2], stock_hexa);*/
        /*load_program(grid, stock_hexa);*/
    }

    free(grid);

    return 0;
}
