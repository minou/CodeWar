#include "struct.h"
#include <stdlib.h>
#include <time.h>

CPU randomCPU(CPU tab[NB_CPU]){
    srand(time(NULL));
    return tab[rand()%NB_CPU];
}

color randomColor(){
    int i = 0;
    color randColor;
    
    srand(time(NULL));
    while (i < 4){
        randColor.color[i] = rand()%HEXA;
    }
    return randColor;
}

int load_program(CPU grid[NB_CPU], unsigned char ** stock_hexa){
    /*CPU p = randomCPU(grid);*/
    return 0;
}
