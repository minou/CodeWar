#include "struct.h"
#include "prototype.h"
#include <stdlib.h>
#include <time.h>
#include <stdio.h>

CPU  randomCPU(CPU * grid){
      int nb = rand()%NB_CPU;
      printf("random_8");
      srand(time(NULL));
      printf("%d\n", nb);
      return grid[nb];
}

color randomColor(){
      int i = 0;
      color randColor;
      srand(time(NULL));
      while (i < 2){
	    printf("random_18");
	    randColor.color[i].number = rand()%HEXA;
	    i++;
      }
      return randColor;

}

