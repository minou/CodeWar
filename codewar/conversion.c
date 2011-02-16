/* an instruction is coded on 16 bits -> 2 octets -> 2 words */
#include "struct.h"

/*the word has already been switch*/

/* this function convert the first 5 bites in hexadecimal
 *  to determine the instruction
 */

word instructionName(word wrd){
    return wrd >> 11;
}

word instructionType(word wrd){
    return (wrd << 5) >> 13;
}

word instructionType2(word wrd){
    return (wrd << 8) >> 13;
}

word instructionValue(word wrd){
    return (wrd & 8);
}

word instructionValue2(word wrd){
    return (wrd & 5);
}
