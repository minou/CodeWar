#include "struct.h"
#include "prototype.h"
#include <stdio.h>
#include <stdlib.h>
/*fetch instruction, passe à l'operation suivante*/
void fetch();

/*execute l'instruction préalablement décoder*/
void execute(word w){}

void decryte(binary * result){
    instruction insts[31] = {
        {"MOVE", 2, NULL, NULL, NULL},
        {"PUSH", 1, NULL, NULL, NULL},
        {"POP", 1, NULL, NULL, NULL},
        {"ADD", 2, NULL, NULL, NULL},
        {"CMP", 2, NULL, NULL, NULL},
        {"SUB", 2, NULL, NULL, NULL},
        {"LSL", 2, NULL, NULL, NULL},
        {"LSR", 2, NULL, NULL, NULL},
        {"AND", 2, NULL, NULL, NULL},
        {"OR", 2, NULL, NULL, NULL},
        {"XOR", 2, NULL, NULL, NULL},
        {"NOT", 1, NULL, NULL, NULL},
        {"BCC/BGT", 1, NULL, NULL, NULL},
        {"BCS/BLT", 1, NULL, NULL, NULL},
        {"BEQ", 1, NULL, NULL, NULL},
        {"BNE", 1, NULL, NULL, NULL},
        {"BLE", 1, NULL, NULL, NULL},
        {"BGE", 1, NULL, NULL, NULL},
        {"BRA", 1, NULL, NULL, NULL},
        {"BSR", 1, NULL, NULL, NULL},
        {"JCC/JGT", 1, NULL, NULL, NULL},
        {"JCS/JLT", 1, NULL, NULL, NULL},
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
    int nb;
    unsigned char s = instructionName(result);
    instruction instru = insts[s];
    if (instru.nbOp == 0){
        /*instru.(*executeZeroOp)();*/
    }
    if (instru.nbOp == 1){
        nb = instructionType(result);
    }

    printf("%s\n", instru.name);
}


/* Permet de passer la l'instruction suivant et l'execute */
void next(CPU * cpu){
    /* Load register R6 or PC */
    binary * result = malloc(sizeof(binary));
    word w = extract(cpu, 0);
    result = conversion(w, result);
    decryte(result);
}
