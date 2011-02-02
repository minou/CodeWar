#include "struct.h"
#include "prototype.h"

word extract(CPU * cpu, int num){
    word word;
    word.word[0] = cpu->RAM[16 + num];
    word.word[1] = cpu->RAM[16 + num + 1];
    return word;
}

word switching(word word){
    word new;
    new[0] = word[1];
    new[1] = word[0];
    return new;
}

void next(CPU * cpu){
    /* Load register R6 or PC */
}
