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

/* an instruction is coded on 16 bits -> 2 octets -> 2 words */
/*the word has already been switch*/

/* this function convert the first 5 bites in hexadecimal
 *  to determine the instruction
 */
word instructionName(word * wrd){
    /*printf("code l'instruction %05x\n",(*wrd >> 11));*/
    return *wrd >> 11;
}

word instructionType(word  wrd){
    printf("type de la premiere instruction %03x\n", (wrd << 5) >> 13 );
    return (wrd << 5) >> 13;
}

word instructionType2(word wrd){
    return (wrd << 8) >> 13;
}

word instructionValue(word wrd){
    return (wrd & 8);
}

word instructionValue2(word wrd){
    return (wrd & 5);
}
