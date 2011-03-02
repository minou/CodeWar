#include "struct.h"
#include "prototype.h"

void add(CPU * cpu, operande op1, operande op2){
    if (op2.type != 0){
        return;
    }
    if ((op1.type >= 0 && op1.type =<3) || op1.type == 4){
        cpu.registers[op2.value] += get_value(cpu, op1);
    }
}
