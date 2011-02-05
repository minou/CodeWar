#include "struct.h"
#include "prototype.h"

/* num correspond à l'instruction que l'on veut et commence à zéro */
word extract(CPU * cpu, int num){
    word word;
    word.word[0] = cpu->RAM[16 + (2 * num)];
    word.word[1] = cpu->RAM[16 + (2 * num) + 1];
    return word;
}

word switching(word w){
    word new;
    new.word[0] = w.word[1];
    new.word[1] = w.word[0];
    return new;
}

void execute(word w){}
char * hexaBinaire(word w){}
void decryte(char *){}
/* Permet de passer la l'instruction suivant et l'execute */
void next(CPU * cpu){
    /* Load register R6 or PC */
}
