#include "struct.h"
#include "prototype.h"
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
int open_load_File(char * file, CPU * cpu){
    int fd, r, i = 16;
    unsigned char * buffer = malloc(HEXA);

    fd = open(file, O_RDONLY);
    if (fd == -1){
        perror("open_in_open_load");
        return -1;
    }
    /*we want to read 240octet and then store it in the CPU
     * the first 16 octets are reserved for the the registers and the color
     * so we start at 16 (in the CPU) to load the program
     * this means that the program cannot weight more than 240octets???
     * we need to know the length of the file 
     */
    while ( (r = read(fd, buffer, HEXA)) != 0){
        if (r == -1){
            perror("read_in_open_load");
            return -1;
        }
        if (r > 0){
            cpu->RAM[i] = buffer[0];/*store octet by octet in the memory*/
            i++;
        }
    }

    printf("\n");
    return 0;
}

int get_file_size(char *file_name){
    FILE *fp;
    int file_size;

    file_size = 0;
    if ((fp = fopen(file_name, "rb" )) == NULL) {
        fprintf(stderr, "Cannot open %s.\n", file_name);
        return(file_size);
    }
    if (fseek(fp, (long)(0), SEEK_END) != 0) {
        fclose(fp);
        return(file_size);
    }

    file_size = (int) (ftell(fp));
    fclose(fp);

    return(file_size);
}
