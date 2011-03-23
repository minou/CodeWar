#include "struct.h"
#include "prototype.h"
#include <time.h>
#include <stdlib.h>


/*In this file we choose randomly the position of the CPU in the grid
 * and the color
 */

int random(int max)
{
    static int init = 0;
    if (!init)
    {
        srand(time(NULL));
        init = 1;
    }
    return rand() % max;
}


int randomCPU(){
    return random(NB_CPU);
}

color randomColor(){
    color randColor;
    randColor = random(65535);
    return randColor;
}
