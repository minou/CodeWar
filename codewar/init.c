#include "struct.h"
#include <stdio.h>

/*initialisation of the CPU memory*/
void setMem(CPU cpu){
    int i, nb;
    nb = 205; /*CD*/
    for(i = 0; i < MEM_SIZE; i++){
        cpu.RAM[i] = nb;
    }
}

/*initialisation of the 8 registers*/
void setReg(CPU cpu){
    int i,nb;
    nb = 51966;
    for(i = 0; i < REG; i++){
        sprintf((cpu.registers[i]).number, "%x", nb);
    }
}

int init(CPU grid[NB_CPU]){
    int i = 0;
    while (i < NB_CPU){
        setMem(grid[i]);
        setReg(grid[i]);
        i++;
    }
    return 0;
}
