
/*JE PENSE QU'IL FAUT REVOIR LES METHODES D'EXTRACT.C, MAIS J'AI DES PROBLEMES 
  AVEC LES ">>" ET LES "<<"
*/

/*how do we access the 2 word of the move???*/
void move(CPU * cpu, operande op1, operande op2){
      if (op1.type >= 0 && op1.type =<3){
	    if ((op2.type >= 0 && op2.type =<3) || op2.type == 5){
	    }
      }
      else if (op1.type == 4 || op1.type == 5){/*cas où t1 est une adresse ou une valeur immediate*/ 
	    if (op2.type >= 0 && op2.type =<3){
		  /* On échange les value pour les mettre dans les bonnes operandes */
		  int value = op1.value;
		  op1.value = op2.value;
		  op2.value = op1.value;
		  
		  /* On récupère la value de la valeur immédiate ou une adresse (v) */
		  value = get_value(op1);
		  if (op2.type == 0){
			cpu->registers[op2.value] = value;
		  }
	    }
      }
      else {
	    printf("Erreur au niveau des types");
	    return;
      }    
     /*if the first operande is an direct value or an adress*/
     if( (op1.type == 4) || (op1.type == 5) ){
     /*then the last third bits of the word code the destination register's number*/
     
	  /* !!!!!!!!  PROBLEME: difference entre rrr (de la fin du premier mot) et op1.value     ????*/
	  cpu.registers[op1.value] = ;
     }
     else{
	   /*  if the source is not a direct value or an adress (op1.type != 4) && (op1.type != 5) 
	       they code the source register's number
	       then the 2 word codes the destination value
	       the possibles values are:
	       a number between 0 and 7
	       an adress on 16 bits
	  */
	   /*case where the second word codes a register's number*/
	   if(w2 >= 0 && w2<=7){
	       cpu.registers[w2] = cpu.registers[op1.value];
	   }
	   /*case where the second word codes an address*/
	   else{
	       *w2 = cpu.registers[op1.value];/*on veut la variable qui se trouve à cette adresse*/
	   }
     }
     /*il faut egalement implementer MOVE.l et MOVE.h
       gerer les modes d'adressage !?
       et gerer le registre d'état
    */         
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