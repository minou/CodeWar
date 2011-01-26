#define NB_LINE 16
#define NB_COLUMN 16

typedef struct word
{
    unsigned int number;
} word;

typedef struct CPU
{
    char RAM[256];
    word registers[8];
} CPU;

typedef struct color
{
    int color;
}color;

void display_grid(CPU grid[256]);
void free2(char ** line);
color get_color(CPU cpu);
