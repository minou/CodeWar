/*the memory is a table of 16 words of 16bits*/
#define NB_LINE 16
#define NB_COLUMN 16
/* the memory size of a CPU is 256 octets*/
#define MEM_SIZE 256
/* there are 8 registers in each CPU*/
#define REG 8
#define NB_CPU 256

#define SIZE_BUFFER 15

#define NB_CPU 256

typedef unsigned short word;

typedef struct CPU
{
    int id;
    unsigned char RAM[MEM_SIZE];
    word registers[REG];
    /*CPU flags, indicates his state*/
    word states;/* the states register, in there we store if an operation generates a carry*/
} CPU;

typedef word color;

enum regist{
    RO,
    R1,
    R2,
    R3,
    R4,
    R5,
    R6,
    PC = R6,
    R7,
    SP = R7
};

typedef struct operande{
    int type;
    int value;
} operande;

typedef struct instruction{
    char name[10];
    int nbOp;
    void (*executeZeroOp)(CPU *);
    void (*executeOneOp)(CPU *, operande);
    void (*executeTwoOp)(CPU *, operande, operande);
}instruction;

extern CPU grid[NB_CPU];
extern CPU **list;
