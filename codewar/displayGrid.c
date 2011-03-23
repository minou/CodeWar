#include <string.h>
#include <stdio.h>
#include "struct.h"
#include "prototype.h"

/* Méthode permettant d'afficher le plateau */
void display_grid()
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
                printf("%04x|", color);
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
    color color;
    color = (cpu->RAM[2] | cpu->RAM[1] << 8);
    return color;
}

int cmp_color(color color_cpu)
{
    if (color_cpu != 0xCDCD){
        return 1;
    }
    return 0;
}
