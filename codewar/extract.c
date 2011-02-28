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
    return *wrd >> 11;
}

word instructionType(word  wrd){
    printf("type de la premiere instruction %03x\n", (wrd << 5) >> 13 );
    return (wrd >> 8) & 3;
}

word instructionType2(word wrd){
    return (wrd >> 5) & 3;
}

word instructionValue(word wrd){
    return (wrd & 8);
}

word instructionValue2(word wrd){
    return (wrd & 5);
}

/*dans le cas du move les bits 6 et 7 c'est h et l pas le type
  donc si je ne me trompe pas, il y a un probleme à ce niveau là
  Je pense que cette fonction n'est valable que dans le cas des instructions à une seule operande
  car pour les ops à deux operandes les bits 6 7 8 codent le registre de destination 
  donc il y a un probleme je pense qu'il faut réécrire les fonctions pour les instructions
  avec 0 opérande, 1 operande, 2 operandes et pour le move...
  */
/* Méthode que pour le Move */
/* Return t1 */
word instructionMoveType(word wrd){
    return (wrd >> 6) & 3;
}

/* Return t2 */
word instructionMoveType2(word wrd){
    return (wrd >> 3) & 3;
}

/* Return r */
word instructionMoveValue(word wrd){
    return (wrd & 3);
}

/* Return v */
word instructionMoveValue2(word wrd){
    return wrd;
}
