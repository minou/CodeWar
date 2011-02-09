/* an instruction is coded on 16 bits -> 2 octets -> 2 words */
#include "struct.h"
#include <stdio.h>

/*the word has already been switch*/
char ** conversion(word w){
     int j, i, reste;
     char result [2][8] ; 
     for(i = 0; i<=1 ; i++){
	  printf("conv:line10\t%d:\t\n",w.word[i]);
	  reste = w.word[i];
	  for (j=0;j<8;j++){
	       result[i][j] = reste%2;
	       reste = reste/2; 
	       printf("result[%d][%d] :",i,j);
	       printf("%d\t",result[i][j]);
	       /*printf("line 17\n");*/
	  }
	  printf("\n");
     }
     printf("conv:line21\n");
     return **result;
     
}
int main(){
     printf("main:line26\n");
     int i, j;
     word w;
     w.word[0] = 205;
     w.word[1] = 216;
     printf("main:line31\n");
     for(i = 0; i<=1; i++){
	  printf("main:line33\n");
	  for (j = 0; j<8; j++){
	       printf("main:line35\n");
	       printf("%d",conversion(w)[i][j]);/*erreur de segmentation*/
	       printf("main:line37\n");
	       printf("%d",i);
	  }
	  printf("\n");
     }


}