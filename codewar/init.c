#include "struct.h"
#include <stdio.h>

/*initialisation of the CPU memory*/
void setMem(CPU cpu){
    int i = 0;
    /*CD*/
    int nb = 205;
    while (i < MEM_SIZE){
        cpu.RAM[i] = nb;
        i++;
    }
}

/*initialisation of the 8 registers*/
void setReg(CPU cpu){
    int i, nb, s;
    nb = 51966;
    for(i = 0; i < REG; i++){
        s = sprintf((cpu.registers[i]).number, "%2x", nb);
    }
}

int init(CPU * grid){
    int i = 0;
    while (i < NB_CPU){
        setMem(grid[i]);
        setReg(grid[i]);
        i++;
    }
    return 0;
}
