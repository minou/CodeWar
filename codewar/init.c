#include "struct.h"
#include <stdio.h>

/*initialisation of the CPU memory*/
void setMem(CPU cpu){
    int i = 0;
    /*CD*/
    int nb = 205;
    while (i < MEM_SIZE){
        cpu.RAM[i].number = nb;
        i++;
    }
}

/*initialisation of the 8 registers*/
void setReg(CPU cpu){
    int i, nb, ca, fe;
    nb = 51966;
    ca = 202;
    fe = 254;
    for(i = 0; i < REG; i++){
        /*sprintf((cpu.registers[i]).reg[0].number, "%2x", ca);*/
        /*sprintf((cpu.registers[i]).reg[1].number, "%2x", fe);*/
        cpu.registers[i].reg[0].number = ca;
        cpu.registers[i].reg[1].number = fe;
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
