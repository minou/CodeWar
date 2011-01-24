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
    int i = 0;
    int nb_malloc = NB_MALLOC;
    int size = SIZE;

    char ** line = malloc(nb_malloc * sizeof(char *));
    
    /* Init */
    while (i < nb_malloc)
    {
        line[i] = malloc(size);
        i++;
    }

    line[0] = "   +----+----+----+----+----+----+----+----+----+----+----+----+----+----+----+----+";

    i = 1;
    while (i < nb_malloc - 1)
    {
        sprintf(line[i], "%d", i-1); 
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
    
    while (i < nb_malloc)
    {
        free(line[i]);
        i++;
    }
    free(line);
}
