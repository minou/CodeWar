#include "struct.h"
#include "prototype.h"
#include <stdlib.h>
#include <time.h>
#include <stdio.h>

/*In this file we choose randomly the position of the CPU in the grid
* and the color
*/

CPU  randomCPU(CPU * grid){
    srand(time(NULL));
    return grid[rand()%NB_CPU];
}

color randomColor(){
    int i = 0;
    color randColor;
    srand(time(NULL));
    while (i < 2){
        randColor.word[i] = rand()%16;
        i++;
    }
    return randColor;
}
