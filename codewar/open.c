#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int openFile(char * file, char ** stock_hexa){
      int fd;
      unsigned char buffer[16];
      fd = open(file, O_RDONLY);
      int r;
      while ((r =read(fd, buffer, 16)) != 0){
	    int i;	
	    for (i=0; i<r; i++) {
		  //stock_hexa[i] = buffer[i];
		  printf("%02x\n", buffer[i]);
		  //printf("%02x\n", stock_hexa[i]);
	    }
      }
      return 0;
}
      
int reverse(char ** buffer){
      return 0;
}
      
int main(int argc, char ** argv){
      char ** stock_hexa;
      openFile(argv[1], stock_hexa);
      //printf("%s\n", stock_hexa[0]);
      return 0;
}