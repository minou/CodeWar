#include "struct.h"
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

/*this function open the file put in parameter and store it in the CPU memory 
* return 0 if everything went smoothly
* return -1 if there is an error
*/
int open_load_File(char * file, unsigned char ** stock_hexa){
     int fd, r, i = 0;
     unsigned char * buffer = malloc(HEXA);
     
     fd = open(file, O_RDONLY);
     if (fd == -1){
	  perror("open_in_open_load");
	  return -1;
     }
     /*we want to read 200bits and then store it in the CPU
     * the first 16octets are reserved for the the registers
     * so we start at 17 (in the CPU) to load the program
     * this means that the program cannot weight more than 240octets???
     * we need to know the lenght of the file 
     */
     while ( (r = read(fd, buffer, HEXA)) != 0){
	  if (r == -1){
	       perror("read_in_open_load");
	       return -1;
	  }
	  printf("ligne 33\n");
	  if (r > 0){
            /*stock_hexa[i] =*/
	    printf("%02x\n", buffer);/*store the 16 first octets in the first line*/
	    i++;
	    /*printf("%d\n", i);*/
	  }
	  printf("%d\n", r);
	  printf("%d\n",i);
     }
     return 0;
}
     int main(int args , char ** argv){
	  char * file = "output";
	  unsigned char ** stock_hexa;
	  open_load_File(file, stock_hexa);
	  int i;
	  for (i = 0; i<HEXA; i++){
	       printf("%s\n", stock_hexa[i]);
	  }
	  return 0;
	  
     }
     
  
  
  
	