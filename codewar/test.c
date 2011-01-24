#include <stdio.h>

/*un "word" est une valeur sur 16bits*/
typedef unsigned short word;

/* la taille de la mémoire d'un CPU est de 256 octets*/
#define MEM_SIZE 256
/* il y a 8 registres par CPU*/
#define REG 8

/*création et initialisation des 8 registres */
word reg[REG] = {0};

/*le compteur du pgm, PC, est le registre R6*/
#define PC 6

/*le registre de pile, SP, est le registre R7*/
#define SP 7

/*la memoire est un tableau de de 16mots de 16bits*/
#define NB_LIGNES 16
#define NB_COLONNES 16

char mem [MEM_SIZE];

/*flags du CPU, indique son état*/
int c;/*flag de retenue, =1 si une op a généré une retenue*/
int z;/*flag de zero-itude, =1 si le resultat d'une op est = 0*/
int n;/*flag de négativité, =1 si le resultat d'une op est < 0*/

char l [17] = {'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F'};

/*affichage de l'état de la mémoire du CPU*/
/*void displayCPU(){
	int i,j,k;
	int w = 0;
	for(i = 0; i < 18; i++){
		
		for(j = 0; j<18; j++){
			printf("%5d", &mem[i]);
			if(j == 15){
				printf("\n");
			}
		}
	}
	printf("\n");
}*/
void display(){
	int k;
	for(k = 0; k<18; k++){
		printf("%d",l[k]);
		printf("\n");
	}
	
}
int main(){
		display();
		return 0;
}

		
	