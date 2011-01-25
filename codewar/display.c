#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "struct.h"

#define NB_LINE 16
#define NB_COLUMN 16
#define NB_MALLOC 18
#define SIZE 40

/* Méthode permettant d'afficher le plateau */
void display_grid(CPU grid[256])
{
    int nb = 1;
    int i = 1;
    int nb_line = NB_LINE;
    int nb_malloc = NB_MALLOC;
    int size = SIZE;

    char ** line = malloc(nb_malloc * sizeof(char *));
    
    /* Init */
    while (i < nb_malloc - 1)
    {
        line[i] = malloc(size);
        i++;
    }

    line[0] = "   +----+----+----+----+----+----+----+----+----+----+----+----+----+----+----+----+";
    line [nb_malloc - 1] = "     0    1    2    3    4    5    6    7    8    9    10   11   12   13   14   15";
    
    i = 1;
    while (i < nb_malloc - 1)
    {
        /*line[i] = itoa(i, line[i], 10);*/
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
        while ((nb % nb_line) != 0){
            char string[4];
            sprintf(string, "%d", grid[nb].color);
            strcat(line[i], string);
            strcat(line[i], "|");
            nb++;
        }
        nb++;
        i++;
    }


    i = 1;
    /* Display */
    while (i < nb_malloc)
    {
        printf("%s\n", line[0]);
        printf("%s\n", line[i]);
        i++;
    }

    free2(line);
}

void free2(char ** line){
    int i = 1;
    int nb_malloc = NB_MALLOC;
    
    while (i < nb_malloc - 1)
    {
        free(line[i]);
        i++;
    }
    free(line);
}
