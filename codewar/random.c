#include "struct.h"
#include "prototype.h"
#include <stdlib.h>
#include <time.h>

/*In this file we choose randomly the position of the CPU in the grid
* and the color
*/

int randomCPU(){
    srand(time(NULL));
    return rand()%NB_CPU;
}

color randomColor(){
    color randColor;
    srand(time(NULL));
    randColor.word = rand()%65535;
    return randColor;
}