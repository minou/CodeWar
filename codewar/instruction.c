
/*how do we access the 2 word of the move???*/
void move(operande op1, operande op2){
     /*if the first operande is an direct value or an adress*/
     if( (op1.type == 4) || (op1.type == 5) ){
     /*then the last third bits of the word code the destination register's number*/
     }
     else{
     /*else they code the source register's number*/
     }
     
     /*if the source is not a direct value or an adress*/ 
     if ( (op1.type != 4) && (op1.type != 5)){
     /*then the 2 word code the destination value
     the possibles values are:
	  a number between 0 and 7
	  an adress on 16 bits
     */
     }
     else{
	  /*else the source is a direct value or an adress*/
     }
     
     
}
