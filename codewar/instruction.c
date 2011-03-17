#include "struct.h"
#include "prototype.h"
#include <stdio.h>

void move(CPU * cpu, operande op1, operande op2){     
    int C;
    int N;
    int Z = 0;
    if (op1.type == 4 || op1.type == 5){/*cas où t1 est une adresse ou une valeur immediate*/ 
        if (op2.type >= 0 && op2.type <=3){/*alors rrr(op1.value) codent le numero de registre(value) de la destination(op2)*/

            int value = op1.value;
            op1.value = op2.value;
            op2.value = value;
            value = get_value(cpu, op1); /* On récupère la valeur immédiate ou une adresse (v) */
            addressing(cpu, op2, value);
        }
    }
    else if (op1.type >= 0 && op1.type <= 3){ /*Sinon rrr(op1.value) codent le numero de registre de la source soit (op1.value)*/
        if ((op2.type >= 0 && op2.type <= 3) || op2.type == 5){/*alors (v) le deuxieme mot (op2.value) code la valeur de destination*/
            int value = get_value(cpu, op1);
            addressing(cpu, op2, value);
        }
    }
    else {
        printf("Erreur au niveau des types\n");
        return;
    }
    C = 0;
    N = (op1.value >> 15);
    if( op1.value == 0) Z = 1;
    cpu->states =  C + Z + N; /*stockage des flags???*/
}

void addressing(CPU * cpu, operande op, int value){
    if (op.type == 0){
        cpu->registers[op.value] = value;
    }
    else if(op.type == 1){/*-(Rn)*/
        cpu->registers[op.value] -=2;
        cpu->RAM[cpu->registers[op.value]] = value;
    }
    else if(op.type == 2){/*(Rn)*/
        word adr = cpu->registers[op.value];
        int line, column, value_adr;
        int num = cpu->id;
        column = (adr >> 12) + (num % 16);
        line = ((adr >> 8) & 4) + (num / 16);
        value_adr = adr & 255;
        printf("Affichage du cpu %d, ard %d, ligne %d, colonne %d, valeur %d, num %d\n", 16 * line + column, adr, line, column, value_adr, num);
        grid[16 * line + column].RAM[value_adr] = value;  
    }
    else if(op.type == 3){/*(Rn)+*/
        cpu->registers[op.value] += 2;
        cpu->RAM[cpu->registers[op.value]] = value;
    }
    else  if(op.type == 5){/*si la destination est une adresse*/

        /*then the first four bites represents the destination cpu column*/

        cpu->RAM[op.value] = value;
    }
}



int get_value(CPU * cpu, operande op){
    /* Registre ok*/
    if (op.type == 0){
        return cpu->registers[op.value];
    }
    /* Registre pré-décrémenté que pour les registres*/
    else if (op.type == 1){
        cpu->registers[op.value] -= 2;
        return cpu->RAM[cpu->registers[op.value]];
    }
    /* Adressage indirect que pour les registres */
    else if (op.type == 2){
        word adr = cpu->registers[op.value];
        int line, column, value_adr;
        int num = cpu->id;
        column = (adr >> 12) + (num % 16);
        line = ((adr >> 8) & 4) + (num / 16);
        value_adr = adr & 8;
        printf("Affichage du cpu %d, ligne %d, colonne %d, valeur %d, num %d\n", 16 * line + column,line, column, value_adr, num);
        return grid[16 * line + column].RAM[value_adr];
    }
    /* Registre post-incrémenté que pour les registres*/
    else if (op.type == 3){
        int value = cpu->RAM[cpu->registers[op.value]];
        cpu->registers[op.value] += 2;
        return value;
    }
    /* Valeur immédiate ok*/
    else if (op.type == 4){
        return op.value;
    }
    /* Adresse ok*/
    else if (op.type == 5){
        return cpu->RAM[op.value];
    }
    return -1;
}

void add(CPU * cpu, operande op1, operande op2){
    if (op2.type != 0){
        return;
    }
    if ((op1.type >= 0 && op1.type <= 3) || op1.type == 4){
        cpu->registers[op2.value] += get_value(cpu, op1);
    }
}
void push(CPU * cpu, operande op){
    if(op.type>=0 && op.type<4){/* pas adresse ni valeur*/
        operande op2;
        op2.type = 1;
        op2.value = 7;
        move(cpu, op, op2);
    }      
}
void pop(CPU * cpu, operande op){
    if(op.type>=0 && op.type<4){
        operande op1;
        op1.type = 3;
        op1.value = 7;
        move(cpu, op1,op);
    }
}
void substract(CPU * cpu, operande op1, operande op2){
    if (op2.type != 0){
        return;
    }
    if ((op1.type >= 0 && op1.type <= 3) || op1.type == 4){
        cpu->registers[op2.value] -= get_value(cpu, op1);
    }
}

/* Pour ligne commande utiliser strtok et fgets */
