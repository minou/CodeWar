#include "struct.h"
#include "prototype.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <time.h>
#include <stdlib.h>


/*In this file we choose randomly the position of the CPU in the grid
* and the color
*/
/*int random(int max){
    int fd;
    unsigned int alea;

    fd = open("/dev/random", O_RDONLY);
    if (fd == -1) {
        perror("Open /dev/random");
        return -1;
    }
    if (read(fd, &alea, sizeof(alea)) == -1){
        perror("Read /dev/random");
        return -1;
    }
    close(fd);
    return alea % max;
}*/

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
