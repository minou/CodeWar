#include "struct.h"
#include "prototype.h"
#include <stdio.h>


/*In this file we initialize the grid of 256 CPU
* in each CPU of this grid we initialize the memory and the registers
*/



/*initialization of the CPU memory*/
void setMem(CPU * cpu){
    int i = 0;
    while (i < MEM_SIZE){
        (cpu->RAM[i]) = 0xCD;
        i++;
    }
}

/*initialization of the 8 registers*/
void setReg(CPU * cpu){
    int i;
    i = 0;
    while (i < REG){
        cpu->registers[i].word = 0xCAFE;
        i++;
    }
}
/*initialization of the grid*/
int init(CPU * grid){
    int i = 0;
    while (i < NB_CPU){
        setMem(&grid[i]);
        setReg(&grid[i]);
        i++;
    }
    return 0;
}
