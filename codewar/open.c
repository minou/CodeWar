#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

#define SIZE_BUFFER 16

int openFile(char * file, unsigned char ** stock_hexa){
    int fd, r;
    int i = 0, j = 0;
    unsigned char * buffer = malloc(SIZE_BUFFER);
    fd = open(file, O_RDONLY);
    if (fd == -1){
        perror("open");
        return -1;
    }
    while ((r = read(fd, buffer, SIZE_BUFFER)) != 0){
        if (r == -1){
            perror("read");
            return -1;
        }
        stock_hexa[i] = buffer;
        i++;
    }
    
    i = 0;
    while (i < 16){
        while (j < SIZE_BUFFER){
            printf("%02x\n", stock_hexa[i][j]);
            j++;
        }
        j = 0;
        i++;
    }

    return 0;
}

int reverse(char ** buffer){
    return 0;
}
