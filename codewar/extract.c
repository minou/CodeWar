#include "struct.h"
#include "prototype.h"
#include <stdio.h>
#include <string.h>

/* num correspond à l'instruction que l'on veut et commence à zéro */
word extract(CPU * cpu, int num){
    word word;
    word = (cpu->RAM[16 + num] | cpu->RAM[16 + num + 1] << 8);
    return word;
}