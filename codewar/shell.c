#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include "ligne_commande.h"
#include "struct.h"
#include "prototype.h"

void display_prompt()
{
    printf("%s", "CodeWar > ");
    fflush(stdout);
}

void run_commande(CPU * grid)
{
    int nb, status, flag, pid;
    char ***bash;

    bash = ligne_commande(&flag, &nb);
    if (bash == NULL){
        exit(0);
    }

    pid = fork();
    if (pid == -1){
	    perror("fork");
	    return;
    }
    if (pid == 0){
        if (nb <= 1){
            commande(bash[0], grid);
        }
        else{
            printf("One command for a line\n");
        }
    }
    else
    {
        if (flag == 0)
        {
            waitpid(pid, &status, 0);
        }
        waitpid(pid, &status, pid);
        libere(bash);
    }
    waitpid(pid, &status, 1);
}

void commande(char ** tab, CPU * grid)
{
    char * option = tab[0];
    /* Display grid */
    if (strcmp(option, "grid") == 0){
        display_grid(grid);
    }

    /* Display CPU */
    if (strcmp(option, "cpu") == 0){
        int nb;
        if (tab[1] == NULL){
            exit(-1);
        }
        nb = atoi(tab[1]);
        if (nb < 0 || nb >= NB_CPU){
            exit(-1);
        }
        displayCPU(grid[nb]);
        displayReg(grid[nb]);
    }
}
