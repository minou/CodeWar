#include "struct.h"
#include "prototype.h"
#include <stdio.h>
/*fetch instruction, passe à l'operation suivante*/
void fetch();

/*execute l'instruction préalablement décoder*/
void execute(word w){}

void decryte(unsigned char s){
    /*int i;*/
    int nb = s;
    instruction insts[33] = {
        {"MOVE", 2, NULL, NULL, NULL},
        {"PUSH", 1, NULL, NULL, NULL},
        {"ADD", 2, NULL, NULL, NULL},
        {"CMP", 2, NULL, NULL, NULL},
        {"SUB", 2, NULL, NULL, NULL},
        {"LSL", 2, NULL, NULL, NULL},
        {"LSR", 2, NULL, NULL, NULL},
        {"AND", 2, NULL, NULL, NULL},
        {"OR", 2, NULL, NULL, NULL},
        {"XOR", 2, NULL, NULL, NULL},
        {"NOT", 1, NULL, NULL, NULL},
        {"BCC", 1, NULL, NULL, NULL},
        {"BGT", 1, NULL, NULL, NULL},
        {"BCS", 1, NULL, NULL, NULL},
        {"BLT", 1, NULL, NULL, NULL},
        {"BEQ", 1, NULL, NULL, NULL},
        {"BNE", 1, NULL, NULL, NULL},
        {"BLE", 1, NULL, NULL, NULL},
        {"BGE", 1, NULL, NULL, NULL},
        {"BRA", 1, NULL, NULL, NULL},
        {"BSR", 1, NULL, NULL, NULL},
        {"JCC/JGT", 1, NULL, NULL, NULL},
        {"JCS", 1, NULL, NULL, NULL},
        {"JLT", 1, NULL, NULL, NULL},
        {"JEQ", 1, NULL, NULL, NULL},
        {"JNE", 1, NULL, NULL, NULL},
        {"JLE", 1, NULL, NULL, NULL},
        {"JGE", 1, NULL, NULL, NULL},
        {"JMP", 1, NULL, NULL, NULL},
        {"JSR", 1, NULL, NULL, NULL},
        {"RTS", 0, NULL, NULL, NULL},
        {"TRAP", 1, NULL, NULL, NULL},
        {"RTE", 0, NULL, NULL, NULL},
    };
    printf("%s\n", insts[nb].name);
}


/* Permet de passer la l'instruction suivant et l'execute */
void next(CPU * cpu){
    /* Load register R6 or PC */
}
