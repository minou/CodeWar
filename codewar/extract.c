#include "struct.h"
#include "prototype.h"
#include <stdio.h>
#include <string.h>

/*retourne l'instruction pointé par PC, quelle dé_indianese et on incremente PC*/
word extract(CPU * cpu){
    word wrd;
    word pc = cpu->registers[6];
    printf("%04x\n", pc);  
    wrd = (cpu->RAM[pc] | cpu->RAM[pc + 1] << 8);
    cpu->registers[6]++;
    return wrd;
}