#include "struct.h"
#include "prototype.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*fetch instruction, passe à l'operation suivante*/
void fetch();

/*execute l'instruction préalablement décoder*/
void execute(word w){}

void decryte(word * result, CPU * cpu){
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
    operande op, op2;
    word s = instructionName(result);
    instruction instru = insts[s];

    if (instru.nbOp == 0){
        /*instru.executeZeroOp(cpu);*/
    }
    if (instru.nbOp == 1){
        op.type = instructionType(*result);
        op.value = instructionValue(*result);
        /*instru.executeOneOp(cpu, op);*/
    }
    if (instru.nbOp == 2){
        /*the Move is a special case we need more data in order to do it*/
        if (strcmp(instru.name, "MOVE") == 0){
            word result2 = extract(cpu);
           /* printf("%04x\n", result2); affiche le deuxieme mot du MOVE*/
            /* t1 */
            op.type = instructionMoveType(*result);
            printf("type de la 1 operande = %d\n",op.type);
            /* r */
            op.value = instructionMoveValue(*result);
            printf("value de la 1 operande = %d\n",op.value);
            /* t2 */
            op2.type = instructionMoveType2(*result);
            printf("type de la 2 operande = %d\n",op2.type);
            /* v */
            op2.value = instructionMoveValue2(result2);
            printf("value de la 2 operande = %d\n",op2.value);
        }
        else{
            op.type = instructionType(*result);
            op.value = instructionValue2(*result);
            op2.type = instructionType2(*result);
        }
        /*instru.executeTwoOp(cpu, op, op2);*/
    }

    printf("le nom de l'instruction est %s\n", instru.name);
}

/* Permet de passer la l'instruction suivant et l'execute */
void next(CPU * cpu){
    /* Load register R6 or PC */
    word result = extract(cpu);
    /*printf("%04x\n", result); affiche le mot extrait*/
    decryte(&result, cpu);
}
