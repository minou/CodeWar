#include "struct.h"
#include "prototype.h"
#include <stdlib.h>
#include <time.h>
#include <stdio.h>

CPU  randomCPU(CPU * grid){
    srand(time(NULL));
    return grid[rand()%NB_CPU];
}

color randomColor(){
    int i = 0;
    color randColor;
    srand(time(NULL));
    while (i < 2){
        randColor.word[i] = rand()%HEXA;
        i++;
    }
    return randColor;
}
