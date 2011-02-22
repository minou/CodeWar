#include "struct.h"
#include "prototype.h"
#include <stdio.h>

int main(int args , char ** argv)
{
    char * option;
    CPU  grid [256];
    char * file;
    int cpu_num;
    CPU * cpu;
    color color_cpu;
    int i = 1;

    option = argv[1];
    if (option == NULL){
        printf("%s\n", "Usage: ./main -programm");
        return -1;
    }
    init(grid);

    while (i < args){
        /* Open and load program in CPU */
        /*load automatiquement pour le momment*/
        file = argv[i];
        cpu_num = randomCPU();
        cpu = &grid[cpu_num];
        color_cpu = randomColor();
        setColor(cpu, color_cpu);
        open_load_File(file, cpu);
        setStack(cpu);
        printf("Program %s loaded in cpu %d (color %04x)\n", file, cpu_num, color_cpu);
        i++;
    }
    while (1) {
        display_prompt();
        run_commande(grid);
    }

    return 0;
}
