#include "struct.h"
#include "prototype.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

CPU grid[256];
CPU ** list;

int init_cpu(int args, char ** argv, int i){
    char * file;
    CPU * cpu;
    color color_cpu;
    int cpu_num;
    while (i < args){
        /* Open and load program in CPU */
        /*load automatiquement pour le momment*/
        file = argv[i];
        cpu_num = randomCPU();
        cpu = &grid[cpu_num];
        cpu->id = cpu_num;
        color_cpu = randomColor();
        setColor(cpu, color_cpu);
        open_load_File(file, cpu);
        setStack(cpu);
        printf("Program %s loaded in cpu %d (color %04x)\n", file, cpu_num, color_cpu);
        i++;
    }
    return 0;
}

int main(int args , char ** argv)
{
    char * option;
    int i = 2;

    option = argv[1];
    if (option == NULL){
        printf("%s\n", "Usage: ./main -programm");
        return -1;
    }
    init(grid);

    if (strcmp(argv[1], "-p") == 0){
        init_cpu(args, argv, i);
        while (1) {
            display_prompt();
            run_commande(grid);
        }
    }
    else if (strcmp(argv[1], "-c")){
        int num = 0;
        int nb = atoi(argv[2]);
        i++;
        init_cpu(args, argv, i);
        display_grid(grid);
        while (num < nb){
            next(&grid[0]);
            num++;
        }
    }

    return 0;
}
