/*the memory is a table of 16 words of 16bits*/
#define NB_LINE 16
#define NB_COLUMN 16
/* the memory size of a CPU is 256 octets*/
#define MEM_SIZE 256
/* there are 8 registers in each CPU*/
#define REG 8

#define HEXA 1
#define SIZE_BUFFER 15

#define NB_CPU 256

typedef unsigned char word;

typedef struct CPU
{
    word RAM[MEM_SIZE];
    word registers[REG][2];
    /*CPU flags, indicates his state*/
    int c;/*carry flag, =1 if a op generates a carry*/
    int z;/*zero flag, =1 if the result of an op is = 0*/
    int n;/*negativity flag, =1 if the result of an op is < 0*/
} CPU;

typedef struct color
{
    word color[2];
}color;

