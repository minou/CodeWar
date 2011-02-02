#include "struct.h"
#include "prototype.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

int main(int args , char ** argv)
{
    char * option;
    CPU  grid [256]; 

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
        char * file = "output";	
        CPU cpu = randomCPU(grid);
        open_load_File(file, &cpu);
        display_grid(grid);
        displayCPU(cpu);
        printf("\n");	  
    }

    return 0;
}
