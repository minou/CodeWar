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
    word stateregister[1];
    /*carry flag, =1 if a op generates a carry*/
    /*zero flag, =1 if the result of an op is = 0*/
    /*negativity flag, =1 if the result of an op is < 0*/
} CPU;

typedef word color;
/*in this structure we store the instruction in binary*/
typedef struct binary{
      int tab [16];
      
}binary;