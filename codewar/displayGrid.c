#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "struct.h"
#include "prototype.h"

#define NB_MALLOC 18

/* Méthode permettant d'afficher le plateau */
void display_grid(CPU * grid)
{
    int nb = 0;
    int i = 1;
    int nb_line = NB_LINE;
    int nb_column = NB_COLUMN;
    int nb_malloc = NB_MALLOC;

    char ** line = malloc(nb_malloc * sizeof(char *));

    /* Init */
    while (i < nb_malloc - 1)
    {
        line[i] = malloc(10 * nb_column + 1);
        i++;
    }

    line[0] = "   +----+----+----+----+----+----+----+----+----+----+----+----+----+----+----+----+";
    line[nb_malloc -1]  = "     0    1    2    3    4    5    6    7    8    9    10   11   12   13   14   15";

    i = 1;
    while (i < nb_malloc - 1)
    {
        sprintf(line[i], "%d", i-1);
        i++;
    }

    i = 1;
    while (i < nb_malloc - 1)
    {
        if (i - 1 < 10){
            strcat(line[i], "  |");
        }
        else{
            strcat(line[i], " |");
        }
        i++;
    }

    /* Display color */
    i = 1;
    while (i < nb_malloc - 1)
    {
        while (nb != nb_line){
            char str[4] ;
            color color = get_color(grid[16 * i + nb]);

            if (cmp_color(color) == 0){
                strcat(line[i], "    ");
            }
            else{
                str[0] = (char) color.color[0];
                str[2] = (char) color.color[1];
                strcat(line[i], str);
            }
            strcat(line[i], "|");
            nb++;
        }
        nb = 0;
        i++;
    }

    i = 1;
    /* Display */
    while (i < nb_malloc - 1)
    {
        printf("%s\n", line[0]);
        printf("%s\n", line[i]);
        i++;
    }
    printf("%s\n", line[0]);
    printf("%s\n", line[nb_malloc - 1]);

    free2(line);
}

void free2(char ** line)
{
    int i = 1;

    while (i < NB_MALLOC - 1)
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
    while (i < 2){
        color.color[i] = cpu.RAM[2 + i];
        i++;
    }
    return color;
}

int cmp_color(color color_cpu){
    unsigned char cd = 205;
    if ((color_cpu.color[0] != cd) && (color_cpu.color[1] != cd)){
        return 1;
    }
    return 0;
}
