#include <string.h>
#include <stdio.h>
#include "struct.h"
#include "prototype.h"

/* Méthode permettant d'afficher le plateau */
void display_grid(CPU * grid)
{
    int i = 0;
    int nb = 0;
    int nb_line = NB_LINE;

    char * init = "   +----+----+----+----+----+----+----+----+----+----+----+----+----+----+----+----+";
    char * end  = "     0    1    2    3    4    5    6    7    8    9    10   11   12   13   14   15";

    while (i < nb_line)
    {
        printf("%s\n", init);
        if (i < 10){
            printf("%d  |", i);
        }
        else{
            printf("%d |", i);
        }
        /* Display color */
        while (nb != nb_line){
            color color = get_color(&grid[(16 * i) + nb]);
            if (cmp_color(color) == 0){
                printf("    |");
            }
            else{
                printf("%02x", color.word[0]);
                printf("%02x|", color.word[1]);
            }
            nb++;
        }
        printf("\n");
        nb = 0;
        i++;
    }
    printf("%s\n", init);
    printf("%s\n", end);
}

color get_color(CPU * cpu)
{
    int i = 0;
    color color;
    while (i < 2){
        color.word[i] = cpu->RAM[1 + i];
        i++;
    }
    return color;
}

int cmp_color(color color_cpu)
{
    unsigned char cd = 205;
    if ((color_cpu.word[0] != cd) || (color_cpu.word[1] != cd)){
        return 1;
    }
    return 0;
}
