#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#define SIZE_BUFFER 16

int openFile(char * file, char ** stock_hexa){
    int i, fd, r;
    unsigned char buffer[SIZE_BUFFER];
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
        for (i = 0; i < r; i++){
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
