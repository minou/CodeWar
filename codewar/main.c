#include "struct.h"
#include "prototype.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

int main(int args , char ** argv)
{
    char * option;
    CPU  grid [256];

    char * file;
    int cpu_num;
    CPU * cpu;
    color color_cpu;

    init(grid);

    /* Open and load program in CPU */
    /*load automatiquement pour le momment*/
    file = "../codewar/output";
    cpu_num = randomCPU();
    cpu = &grid[cpu_num];
    color_cpu = randomColor();
    setColor(cpu, color_cpu);
    open_load_File(file, cpu);
    setStack(cpu);

    printf("Program %s loaded in cpu %d (color %04x)\n", file, cpu_num, color_cpu);

    /*option = argv[1];*/
    /*if (option == NULL){*/
    /*printf("%s\n", "Usage: ./main -option");*/
    /*return -1;*/
    /*}*/

    while (1) {
        display_prompt();
        run_commande(grid);
    }

    if (strcmp(option, "-f") == 0){
        display_grid(grid);
        displayCPU(*cpu);
        printf("\n");
        next(cpu);
        next(cpu);
        next(cpu);
        next(cpu);
        next(cpu);
        next(cpu);
    }

    return 0;
}
