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
    int fd = open(file, O_RDONLY);
    if (fd == -1)
    {
        perror(file);
        return -1;
    }

    read(fd, cpu->RAM + 0x10, 240);
    return 0;
}

void setColor(CPU * cpu, color c){
    cpu->RAM[1] = c >> 8;
    cpu->RAM[2] = c;
}
void setStack(CPU * cpu){
    cpu->registers[6] = 0x10;
}

int get_file_size(char * file_name){
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
