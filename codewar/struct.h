typedef struct word
{
    unsigned int number;
} word;

typedef struct CPU
{
    int color;
    char RAM[256];
    word registers[8];
} CPU;

void display_grid(CPU grid[256]);
void free2(char ** line);
