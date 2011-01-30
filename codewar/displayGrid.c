#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "struct.h"

#define NB_MALLOC 18

/* Méthode permettant d'afficher le plateau */
void display_grid(CPU grid[256])
{
    int nb = 1;
    int i = 1;
    int nb_line = NB_LINE;
    int nb_column = NB_COLUMN;
    int nb_malloc = NB_MALLOC;

    /*char * p = "   +----+----+----+----+----+----+----+----+----+----+----+----+----+----+----+----+";*/
    /*char  * f = "     0    1    2    3    4    5    6    7    8    9    10   11   12   13   14   15";*/
    unsigned char ** line = malloc(nb_malloc * sizeof(char *));
    
    /* Init */
    while (i < nb_malloc - 1)
    {
        line[i] = malloc(5 * nb_column + 1);
        i++;
    }

    
    /*i = 1;*/
    /*while (i < nb_malloc - 1)*/
    /*{*/
        /*sprintf(line[i], "%d", i-1);*/
        /*i++;*/
    /*}*/

    /*i = 1;*/
    /*while (i < nb_malloc - 1)*/
    /*{*/
        /*if (i - 1 < 10){*/
            /*strcat(line[i], "  |");*/
        /*}*/
        /*else{*/
            /*strcat(line[i], " |");*/
        /*}*/
        /*i++;*/
    /*}*/
    
    /* Display color */
    i = 1;
    while (i < nb_malloc - 1)
    {
        while ((nb % nb_line) != 0){
            /*unsigned char string[4];*/
            color color = get_color(grid[nb]);
            /*if (cmp_color(color) == 0){*/
                /*strcat(string, "   ");*/
            /*}*/
            /*else{*/
            /*sprintf(string, "%s", color.color);*/
            /*}*/
            /*printf("%s \n", color.color);*/
            line[i] = color.color;
            /*strcat(line[i], "|");*/
            nb++;
        }
        nb++;
        i++;
    }

    i = 1;
    /* Display */
    while (i < nb_malloc - 1)
    {
        /*printf("%s\n", line[0]);*/
        printf("%s\n", line[i]);
        i++;
    }

    free2(line);
}

void free2(unsigned char ** line)
{
    int i = 1;
    int nb_malloc = NB_MALLOC;
    
    while (i < nb_malloc - 1)
    {
        free(line[i]);
        i++;
    }
    free(line);
}

color get_color(CPU cpu)
{
    int i = 0;
    color color;
    while (i < 4){
        color.color[i] = cpu.RAM[2 + i];
        i++;
    }
    return color;
}

int cmp_color(color color_cpu){
    int i = 0;
    while (i < 4){
        if (color_cpu.color[i] != 205){
            return 1;
        }
        i++;
    }
    return 0;
}
