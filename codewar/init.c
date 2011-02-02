#include "struct.h"
#include <stdio.h>

/*initialisation of the CPU memory*/
void setMem(CPU *cpu){
    int i = 0;
    /*CD*/
    int nb = 205;
    while (i < MEM_SIZE){
        (cpu->RAM[i]).number = nb;
        i++;
    }
}

/*initialisation of the 8 registers*/
void setReg(CPU * cpu){
    int i, ca, fe;
    ca = 202;
    fe = 254;
    for(i = 0; i < REG; i++){
        (cpu->registers[i]).reg[0].number = ca;
        (cpu->registers[i]).reg[1].number = fe;
    }
}

int init(CPU * grid){
    int i = 0;
    while (i < NB_CPU){
        setMem(&grid[i]);
        setReg(&grid[i]);
        i++;
    }
    return 0;
}
