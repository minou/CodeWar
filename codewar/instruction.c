#include "struct.h"
#include "prototype.h"

void move(CPU * cpu, operande op1, operande op2){     
      if (op1.type == 4 || op1.type == 5){/*cas où t1 est une adresse ou une valeur immediate*/ 
	    if (op2.type >= 0 && op2.type =<3){
		  /*alors rrr(op1.value) codent le numero de registre(value) de la destination(op2)*/
		  int value = op1.value;
		  op1.value = op2.value;
		  op2.value = value;
		 
		  value = get_value(op1); /* On récupère la valeur immédiate ou une adresse (v) */
		  
		  if (op2.type == 0){
			cpu->registers[op2.value] = value;
		  }
	    }
      }
      else if (op1.type >= 0 && op1.type =<3){ /*Sinon rrr(op1.value) codent le numero de registre de la source soit (op1.value)*/
	    if ((op2.type >= 0 && op2.type =<3) || op2.type == 5){/*alors (v) le deuxieme mot (op2.value) code la valeur de destination*/
		  if (op1.type == 0){/*si adressage direct pour la source*/
			if(op2.type == 0){/*si adressage direct pour la destination*/
			      /*cas du move de registre direct à registre direct*/
			      cpu->registers[op2.value] = cpu->registers[op1.value];
			}
			if(op2.type == 5){/*si la destination est une adresse*/
			    /*op2.value c'est l'adresse mais pas la vrai, accès réel impossible*/  
			}
	    }
      }
      else {
	    printf("Erreur au niveau des types");
	    return;
      }    

int get_value(CPU * cpu, operande op){
      /* Registre ok*/
      if (op.type == 0){
	    return cpu->registers[op.value];
      }
      /* Registre pré-décrémenté que pour les registres*/
      else if (op.type == 1){
	   
      }
      /* Adressage indirect que pour les registres */
      else if (op.type == 2){
	    return * cpu->registers[op.value];
      }
      /* Registre post-incrémenté que pour les registres*/
      else if (op.type == 3){
	    
      }
      /* Valeur immédiate ok*/
      else if (op.type == 4){
	    return op.value;
      }
      /* Adresse ok*/
      else if (op.type == 5){
	    return *op.value;
      }
}