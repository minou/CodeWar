#include "struct.h"
#include "prototype.h"
#include <stdio.h>


/*In this file we initialize the grid of 256 CPU
* in each CPU of this grid we initialize the memory and the registers
*/



/*initialization of the CPU memory*/
void setMem(CPU * cpu){
    int i = 0;
    int nb = 205;/*CD*/
    while (i < MEM_SIZE){
        (cpu->RAM[i]) = nb; 	
        i++;
    }
}

/*initialization of the 8 registers*/
void setReg(CPU * cpu){
    int i, ca, fe;
    i = 0;
    ca = 202;
    fe = 254;
    while (i < REG){
        cpu->registers[i].word[0] = ca;
        cpu->registers[i].word[1] = fe;
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
