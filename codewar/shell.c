#include <stdio.h>

void display_prompt()
{
    printf("%s", "CodeWar > ");
    fflush(stdout);
}


int main(int args , char ** argv)
{
    display_prompt();
    return 0;
}
