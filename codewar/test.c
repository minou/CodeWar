#include <stdio.h>
#include "struc_iut.h"

/*a "word" est une valeur sur 16bits*/
word w;

/*the program counter, PC, is the register R6*/
#define PC 6

/*the heap register, SP, is the register R7*/
#define SP 7

CPU cpu;

char l [16] = {'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F'};

void display(){
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
}
/*initialisation of the CPU memory*/
void setMem(){
      int i,nb;
      nb = 205;
      for(i = 0;i<MEM_SIZE;i++){
	    cpu.RAM[i] = nb;
      }
}
/*affichage de l'état de la mémoire du CPU*/
void displayCPU(){
	int i,j;
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
/*initialisation of the 8 registers*/
void setReg(){
      int i,nb;
      nb = 51966;
      for(i = 0;i<REG;i++){
	    sprintf((cpu.registers[i]).number, "%x", nb);
      }
}
/*display the 8 registers*/
void displayReg(){
      int i;     
      for(i = 0;i<REG;i++){
	printf("  R%d: 0x%s\n",i,cpu.registers[i].number);
      }   
}
int main(){
      setMem();
      display();
      displayCPU();
      setReg();
      displayReg();
      return 0;
}

		
	