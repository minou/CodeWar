#include "struct.h"
#include "prototype.h"
#include <stdlib.h>
#include <time.h>
#include <stdio.h>

CPU  randomCPU(CPU * grid){
      int nb = rand()%NB_CPU;
      srand(time(NULL));
      return grid[nb];
}

color randomColor(){
      int i = 0;
      color randColor;
      srand(time(NULL));
      while (i < 2){
	    randColor.color[i] = rand()%HEXA;
	    i++;
      }
      return randColor;

}

