#include "struct.h"

word extract(CPU cpu, int num){
    word word;
    word.word[0] = cpu.RAM[16 + num];
    word.word[1] = cpu.RAM[16 + num + 1];
    return word;
}

word switching(word word){
    return word;
}
