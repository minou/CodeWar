#include "struct.h"
#include "prototype.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

CPU grid[NB_CPU];
CPU **list;

int init_cpu(int args, char ** argv, int i){
    char * file;
    color color_cpu;
    int cpu_num;
    int nb = 0;
    list = malloc((args - i + 1) * sizeof(CPU *));
    while (i < args){
        /* Open and load program in CPU */
        /*load automatiquement pour le momment*/
        file = argv[i++];
        cpu_num = randomCPU();
        list[nb] = &grid[cpu_num];
        list[nb]->id = cpu_num;
        color_cpu = randomColor();
        setColor(list[nb], color_cpu);
        open_load_File(file, list[nb]);
        setStack(list[nb]);
        printf("Program %s loaded in cpu %d (color %04x)\n", file, cpu_num, color_cpu);
        nb++;
    }
    list[nb] = NULL;
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

    if (strcmp(option, "-p") == 0){
        init_cpu(args, argv, i);
        while (1) {
            display_prompt();
            run_commande(grid);
        }
    }
    else if (strcmp(option, "-c") == 0){
        int num = 0;
        int nb = atoi(argv[2]);
        init_cpu(args, argv, ++i);
        printf("Board at game start\n");
        display_grid(grid);
        while (num++ < nb){
            next();
        }
        printf("Board at end of game (%d cycles done)\n", nb);
        display_grid(grid);
    }
    free(list);
    return 0;
}
