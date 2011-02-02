#include "struct.h"
#include "prototype.h"
#include <stdio.h>

/*initialisation of the CPU memory*/
void setMem(CPU * cpu){
    int i = 0;
    int nb = 205;/*CD*/
    while (i < MEM_SIZE){
        (cpu->RAM[i]) = nb; 	
        i++;
    }
}

void setColor(CPU * cpu){
    color c = randomColor();
    cpu->RAM[1] = c.color[0];
    cpu->RAM[2] = c.color[1];
}

/*initialisation of the 8 registers*/
void setReg(CPU * cpu){
    int i, ca, fe;
    i = 0;
    ca = 202;
    fe = 254;
    while (i < REG){
        cpu->registers[i][0] = ca;
        cpu->registers[i][1] = fe;
        i++;
    }
}

int init(CPU * grid){
    int i = 0;
    while (i < NB_CPU){
        setMem(&grid[i]);
        setReg(&grid[i]);
        setColor(&grid[i]);
        i++;
    }
    return 0;
}
