
/*JE PENSE QU'IL FAUT REVOIR LES METHODES D'EXTRACT.C, MAIS J'AI DES PROBLEMES 
  AVEC LES ">>" ET LES "<<"
*/

/*how do we access the 2 word of the move???*/
void move(CPU * cpu, operande op1, operande op2){
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
