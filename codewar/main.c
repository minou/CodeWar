#include "struct.h"

int main(int args , char ** argv)
{
    CPU grid[256];
    display_grid(grid);

    setMem();
    displayCPU();
    setReg();
    displayReg();

    char ** stock_hexa;
    openFile(argv[1], stock_hexa);
    //printf("%s\n", stock_hexa[0]);

    return 0;
}
