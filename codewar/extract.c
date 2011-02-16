#include "struct.h"
#include "prototype.h"
#include <stdio.h>
#include <string.h>

/*retourne l'instruction pointé par PC, quelle dé_indianese et on incremente PC*/
word extract(CPU * cpu){
    word wrd;
    word pc = cpu->registers[6];
    wrd = (cpu->RAM[pc] | cpu->RAM[pc + 1] << 8);  
    printf("PC = %04x\n", pc);  
    cpu->registers[6]+=2;
    return wrd;
}