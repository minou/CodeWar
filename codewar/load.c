#include "struct.h"
#include <stdlib.h>
#include <time.h>
#include <stdio.h>

CPU randomCPU(CPU tab[NB_CPU]){
    srand(time(NULL));
    return tab[rand()%NB_CPU];
}

color randomColor(){
    int i = 0;
    color randColor;
    
    srand(time(NULL));
    while (i < 4){
        randColor.color[i] = rand()%HEXA;
    }
    return randColor;
}

int load_program(CPU grid[NB_CPU], unsigned char ** stock_hexa){
    int l, c;
    int i = 16;
    CPU p = randomCPU(grid);
    printf("%s\n", "Avant while");
    while (i < (HEXA * SIZE_BUFFER)){
        l = (i / HEXA) - 1;
        c = i % HEXA;
        printf("l = %d c = %d\n", l, c);
        /*if (stock_hexa[l][c] == NULL){*/
            /*printf("l = %d c = %d\n", l, c);*/
        /*}*/
        printf("%02x\n", stock_hexa[l][c]);
        p.RAM[i] = stock_hexa[l][c];
        i++;
    }
    printf("%s\n", "Aprés while");
    return 0;
}
