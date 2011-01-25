#include <stdio.h>

/*un "word" est une valeur sur 16bits*/
typedef unsigned short word;

/* the memory size of a CPU is 256 octets*/
#define MEM_SIZE 256
/* there are 8 registers in each CPU*/
#define REG 8

/*creation & initialisation of the 8 registers*/
word reg[REG] = {0};

/*the program counter, PC, is the register R6*/
#define PC 6

/*the heap register, SP, is the register R7*/
#define SP 7

/*the memory is a table of 16 words of 16bits*/
#define NB_LINES 16
#define NB_COLUMNS 16

char mem [MEM_SIZE];

/*CPU flags, indicates his state*/
int c;/*carry flag, =1 if a op generates a carry*/
int z;/*zero flag, =1 if the result of an op is = 0*/
int n;/*negativity flag, =1 if the result of an op is < 0*/

char l [16] = {'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F'};
/*affichage de l'état de la mémoire du CPU*/
void displayCPU(){
	int i,j;
	for(i = 0; i < 16; i++){
		printf("|  0x%c0  |",l[i]);
		for(j = 0; j<16; j++){
			printf("%4c%c",l[0],l[0] );
			if(j == 15){
				printf("  |");
				printf("\n");
			}
		}
	}
	printf("---------+-----------------------------------------------------------------------------------");
	printf("\n");
}
void display(){
	int k;
	printf("---------+-----------------------------------------------------------------------------------");
	printf("\n");
	printf("|        |");
	for(k = 0; k<16; k++){
		printf("%5c",l[k]);	
	}
	printf("  |");
	printf("\n");
	printf("---------+-----------------------------------------------------------------------------------");
	printf("\n");
}
int main(){
	
    display();
    displayCPU();
    return 0;
}

		
	