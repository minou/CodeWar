#include "struct.h"
#include "prototype.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

int main(int args , char ** argv)
{
    char * option;
    CPU  grid [256]; 

    init(grid);

    option = argv[1];
    if (option == NULL){
        printf("%s\n", "Usage: ./main -option");
        return -1;
    }

    /* Display grid */
    if (strcmp(option, "-g") == 0){
        display_grid(grid);
    }

    /* Display CPU */
    if (strcmp(option, "-c") == 0){
        int nb;
        if (argv[2] == NULL){
            return -1;
        }
        nb = atoi(argv[2]);
        if (nb < 0 || nb >= NB_CPU){
            return -1;
        }
        displayCPU(grid[nb]);
        displayReg(grid[nb]);
    }

    /* Open and load program in CPU */
    if (strcmp(option, "-f") == 0){
        char * file = "output";
        int cpu_num = randomCPU();
        CPU * cpu = &grid[cpu_num];
        color color_cpu = randomColor();
        setColor(cpu, color_cpu);
        open_load_File(file, cpu);
        printf("Program %s loaded in cpu %d (color %02x%02x)\n", file, cpu_num, color_cpu.word[0], color_cpu.word[1]);
        display_grid(grid);
        displayCPU(*cpu);
        printf("\n");
    }
    if (strcmp(option, "-conv") == 0){
     int  j;
     word w;
     binary * result = malloc(sizeof(binary));
     w.word[0] = 205;
     w.word[1] = 216;
     result = conversion(w, result);

	  for (j = 0; j<16; j++){
	       printf("result[%d] :",j);
	       printf("%d\t",result->tab[j]);
	  }
	  printf("\n");

    }
    return 0;
}
