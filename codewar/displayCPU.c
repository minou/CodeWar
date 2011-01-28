#include "struct.h"
#include <stdio.h>

/*a "word" est une valeur sur 16bits*/
word w;

/*the program counter, PC, is the register R6*/
#define PC 6

/*the heap register, SP, is the register R7*/
#define SP 7

char l [16] = {'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F'};

/*affichage de l'état de la mémoire du CPU*/
void displayCPU(CPU cpu){
    int i,j;
    int k;
    printf("---------+-------------------------------------------------------------------");
    printf("\n");
    printf("|        |");
    for(k = 0; k<16; k++){
        printf("%4c",l[k]);	
    }
    printf("  |");
    printf("\n");
    printf("---------+-------------------------------------------------------------------");
    printf("\n");
    for(i = 0; i < 16; i++){
        printf("|  0x%c0  |",l[i]);
        for(j = 0; j<16; j++){
            printf("%4x",cpu.RAM[i] );
            if(j == 15){
                printf("  |");
                printf("\n");
            }
        }
    }
    printf("---------+-------------------------------------------------------------------");
    printf("\n");
}

/*display the 8 registers*/
void displayReg(CPU cpu){
    int i;
    for(i = 0;i<REG;i++){
        printf("  R%d: 0x%s\n",i,cpu.registers[i].number);
    }   
}
