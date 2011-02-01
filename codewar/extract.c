#include "struct.h"

word extract(CPU cpu, int num){
    word word;
    word = cpu.RAM[16 + num];
    return word;
}
