/*the memory is a table of 16 words of 16bits*/
#define NB_LINE 16
#define NB_COLUMN 16
/* the memory size of a CPU is 256 octets*/
#define MEM_SIZE 256
/* there are 8 registers in each CPU*/
#define REG 8

#define SIZE_BUFFER 15

#define NB_CPU 256

typedef struct word
{
    unsigned char word[2];
}word;

typedef struct CPU
{
    unsigned char RAM[MEM_SIZE];
    word registers[REG];
    /*CPU flags, indicates his state*/
    int c;/*carry flag, =1 if a op generates a carry*/
    int z;/*zero flag, =1 if the result of an op is = 0*/
    int n;/*negativity flag, =1 if the result of an op is < 0*/
} CPU;

typedef word color;

typedef struct binary{
      int tab [16];
      
}binary;

enum regist{
    RO;
    R1;
    R2;
    R3;
    R4;
    R4;
    R5;
    R6;
    PC = R6;
    R7;
    SP = R7;
}

typedef struct instruction{
    char name[10];
    int nbOp;
    void (*executeZeroOp());
    void (*executeOneOp(operande));
    void (*executeTwoOp(operande, operande));
}instruction;

typedef struct operande{
    int type;
    int value;
} operande;

instruction insts[]{
    {"MOVE", 2, NULL, NULL, move};
    {"PUSH", 1, NULL, push, NULL};
    {"ADD", 2, NULL, NULL, add};
    {"CMP", 2, NULL, NULL, cmp};
    {"SUB", 2, NULL, NULL, sub};
    {"LSL", 2, NULL, NULL, lsl};
    {"LSR", 2, NULL, NULL, lsr};
    {"AND", 2, NULL, NULL, and};
    {"OR", 2, NULL, NULL, or};
    {"XOR", 2, NULL, NULL, xor};
    {"NOT", 1, NULL, not, NULL};
    {"BCC", 1, NULL, bcc, NULL};
    {"BGT", 1, NULL, bgt, NULL};
    {"BCS", 1, NULL, bcs, NULL};
    {"BLT", 1, NULL, blt, NULL};
    {"BEQ", 1, NULL, beq, NULL};
    {"BNE", 1, NULL, bne, NULL};
    {"BLE", 1, NULL, ble, NULL};
    {"BGE", 1, NULL, bge, NULL};
    {"BRA", 1, NULL, bra, NULL};
    {"BSR", 1, NULL, bsr, NULL};
    {"JCC", 1, NULL, jcc, NULL};
    {"JGT", 1, NULL, jgt, NULL};
    {"JCS", 1, NULL, jcs, NULL};
    {"JLT", 1, NULL, jlt, NULL};
    {"JEQ", 1, NULL, jeq, NULL};
    {"JNE", 1, NULL, jne, NULL};
    {"JLE", 1, NULL, jle, NULL};
    {"JGE", 1, NULL, jge, NULL};
    {"JMP", 1, NULL, jmp, NULL};
    {"JSR", 1, NULL, jsr, NULL};
    {"RTS", 0, NULL, rts, NULL};
    {"TRAP", 1, NULL, trap, NULL};
    {"RTE", 0, NULL, rte, NULL};
}
