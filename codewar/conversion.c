/* an instruction is coded on 16 bits -> 2 octets -> 2 words */
#include "struct.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/*the word has already been switch*/
binary * conversion(word w, binary * result){
    int j, i, reste;
    for(i = 0; i < 2; i++){
        reste = w.word[i];
        for (j = 0; j < 8; j++){
            result->tab[15 - (7 * i + j)] = reste % 2;
            reste = reste / 2;
        }
    }
    return result;
}

/*this function convert the first 5 bites in hexadecimal
 * to determine the instruction
 */
unsigned char instructionName(binary * bin){
    int i = 0;
    int nb = 0;
    unsigned char result;
    while (i < 5){
        nb += bin->tab[4 - i] * (int)pow(i, 2);
        i++;
    }
    result = nb;
    return result;
}

unsigned char instructionType(binary * bin){
    int i = 0;
    int nb = 0;
    unsigned char result;
    while (i < 3){
        nb += bin->tab[2 + 5 - i] * (int)pow(i, 2);
        i++;
    }
    result = nb;
    return result;
}

unsigned char instructionType2(binary * bin){
    int i = 0;
    int nb = 0;
    unsigned char result;
    while (i < 3){
        nb += bin->tab[2 + 8 - i] * (int)pow(i, 2);
        i++;
    }
    result = nb;
    return result;
}

unsigned char instructionValue(binary * bin){
    int i = 0;
    int nb = 0;
    unsigned char result;
    while (i < 8){
        nb += bin->tab[7 + 8 - i] * (int)pow(i, 2);
        i++;
    }
    result = nb;
    return result;
}

unsigned char instructionValue2(binary * bin){
    int i = 0;
    int nb = 0;
    unsigned char result;
    while (i < 5){
        nb += bin->tab[4 + 11 - i] * (int)pow(i, 2);
        i++;
    }
    result = nb;
    return result;
}
