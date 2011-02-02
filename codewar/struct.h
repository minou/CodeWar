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

typedef struct word
{
    unsigned char number;
} word;

typedef struct regist
{
    word reg[2];
} regist;

typedef struct CPU
{
    word RAM[MEM_SIZE];
    regist registers[REG];
    /*CPU flags, indicates his state*/
    int c;/*carry flag, =1 if a op generates a carry*/
    int z;/*zero flag, =1 if the result of an op is = 0*/
    int n;/*negativity flag, =1 if the result of an op is < 0*/
} CPU;

typedef struct color
{
    word color[2];
}color;

/* FIle displayGrid */
void display_grid(CPU grid[NB_CPU]);
void free2(char ** line);
color get_color(CPU cpu);
int cmp_color(color color_cpu);

/* File displayCPU */
void displayCPU(CPU cpu);
void displayReg(CPU cpu);

/* File open */
int openFile(char * file, unsigned char ** stock_hexa);
int reverse(char ** buffer);

/* Load */
CPU randomCPU(CPU tab[NB_CPU]);
color randomColor();
int open_load_File(char * file, CPU cpu);

/* File init */
int init(CPU * grid);
void setMem(CPU * cpu);
void setReg(CPU * cpu);
