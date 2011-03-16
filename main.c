#include "struct.h"
#include "prototype.h"
#include <stdio.h>
#include <string.h>

int init_cpu(int args, char ** argv, CPU grid[256], int i){
    char * file;
    CPU * cpu;
    color color_cpu;
    int nb;
    printf("10\n");
    while (i < args){
        /* Open and load program in CPU */
        /*load automatiquement pour le momment*/
        printf("14\n");
        file = argv[i];
        printf("16\n");
        nb = randomCPU();
        printf("18\n");
        cpu = &grid[cpu->id];
        cpu.id = nb;
        printf("19\n");
        color_cpu = randomColor();
        setColor(cpu, color_cpu);
        printf("20\n");
        open_load_File(file, cpu);
        setStack(cpu);
        printf("Program %s loaded in cpu %d (color %04x)\n", file, cpu->id, color_cpu);
        i++;
    }
    return 0;
}

int main(int args , char ** argv)
{
    char * option;
    CPU  grid [256];
    int i = 2;

    option = argv[1];
    if (option == NULL){
        printf("%s\n", "Usage: ./main -programm");
        return -1;
    }
    init(grid);

    if (strcmp(argv[1], "-p") == 0){
        init_cpu(args, argv, grid, i);
        while (1) {
            display_prompt();
            run_commande(grid);
        }
    }
    else if (strcmp(argv[1], "-c")){
        /*int nb = argv[2];*/
        /*i = 3;*/
    }
    return 0;
}
