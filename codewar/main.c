#include "struct.h"
#include "prototype.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

int main(int args , char ** argv)
{
    char * option;
    CPU  grid [256];
    
    char * file;
    int cpu_num;
    CPU * cpu;
    color color_cpu;
    
    init(grid);
 
    /*load automatiquement pour le momment*/
    file = "../codewar/output";
    cpu_num = randomCPU();
    cpu = &grid[cpu_num];
    color_cpu = randomColor();
    setColor(cpu, color_cpu);
    open_load_File(file, cpu);
    setStack(cpu);
    
    printf("Program %s loaded in cpu %d (color %04x)\n", file, cpu_num, color_cpu);
    
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
       /* char * file = "../codewar/output";
        int cpu_num = randomCPU();
        CPU * cpu = &grid[cpu_num];
        color color_cpu = randomColor();
        setColor(cpu, color_cpu);
        open_load_File(file, cpu);
        printf("Program %s loaded in cpu %d (color %04x)\n", file, cpu_num, color_cpu);
	*/
        display_grid(grid);
        displayCPU(*cpu);
        printf("\n");
	next(cpu);
	next(cpu);
	next(cpu);
    }

    if (strcmp(option, "-test") == 0){
        next(&grid[0]);
    }

    return 0;
}
