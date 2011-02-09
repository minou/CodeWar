/* an instruction is coded on 16 bits -> 2 octets -> 2 words */
#include "struct.h"
#include <stdio.h>
#include <stdlib.h>

/*the word has already been switch*/
binary * conversion(word w, binary * result){
     int j, i, reste;
     for(i = 0; i<=1 ; i++){
	  reste = w.word[i];
	  for (j=0;j<8;j++){
	       result->tab[i][7 - j] = reste%2;
	       reste = reste/2; 
	  }
     }
     return result;    
}
