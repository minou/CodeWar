/* an instruction is coded on 16 bits -> 2 octets -> 2 words */
#include "struct.h"

char * HexaToBinary(word w){
     /*the word given in parameter is switched*/
     /*this is where we store the word coded in binary 
     * for example word[0] = C9  we store the C in the first case and the 9 in the second
     * to do that we need to isolate the C and the 9
     */
     char result[2][4];
     int i = 0;
     while(i<2){
	  switch (w.word[i]) {
	       case '0' :  result[i][3] = 0; result[i][2] = 0; result[i][1] = 0; result[i][0] = 0;
			      i++;
			      break;
	       case '1' :  result[i][3] = 0; result[i][2] = 0; result[i][1] = 0; result[i][0] = 1;
			      i++;
			      break;
	       case '2' :  result[i][3] = 0; result[i][2] = 0; result[i][1] = 1; result[i][0] = 0;
			      i++;
			      break;
	       case '3' :  result[i][3] = 0; result[i][2] = 0; result[i][1] = 1; result[i][0] = 1;
			      i++;
			      break;
	       case '4' :  result[i][3] = 0; result[i][2] = 1; result[i][1] = 0; result[i][0] = 0;
			      i++;
			      break;
	       case '5' :  result[i][3] = 0; result[i][2] = 1; result[i][1] = 0; result[i][0] = 1;
			      i++;
			      break;
	       case '6' :  result[i][3] = 0; result[i][2] = 1; result[i][1] = 1; result[i][0] = 0;
			      i++;
			      break;
	       case '7' :  result[i][3] = 0; result[i][2] = 1; result[i][1] = 1; result[i][0] = 1;
			      i++;
			      break;
	       case '8' :  result[i][3] = 1; result[i][2] = 0; result[i][1] = 0; result[i][0] = 0;
			      i++;
			      break;
	       case '9' :  result[i][3] = 1; result[i][2] = 0; result[i][1] = 0; result[i][0] = 1;
			      i++;
			      break;
	       case 'A' :  result[i][3] = 1; result[i][2] = 0; result[i][1] = 1; result[i][0] = 0;
			      i++;
			      break;
	       case 'B' :  result[i][3] = 1; result[i][2] = 0; result[i][1] = 1; result[i][0] = 1;
			      i++;
			      break;
	       case 'C' :  result[i][3] = 1; result[i][2] = 1; result[i][1] = 0; result[i][0] = 0;
			      i++;
			      break;
	       case 'D' :  result[i][3] = 1; result[i][2] = 1; result[i][1] = 0; result[i][0] = 1;
			      i++;
			      break;
	       case 'E' :  result[i][3] = 1; result[i][2] = 1; result[i][1] = 1; result[i][0] = 0;
			      i++;
			      break;
	       case 'F' :  result[i][3] = 1; result[i][2] = 1; result[i][1] = 1; result[i][0] = 1;
			      i++;
			      break;
	       default : return result[i][3] = -1; result[i][2] = -1; result[i][1] = -1; result[i][0] = -1; i++;
	}
     }
     return result;
     
}
