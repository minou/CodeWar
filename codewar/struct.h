typedef struct word
{
    unsigned int number;
} word;

typedef struct CPU
{
    char RAM[256];
    word registers[8];
} CPU;

void display_grid(CPU grid[256]);
