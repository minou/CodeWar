#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include "ligne_commande.h"
#include "struct.h"
#include "prototype.h"
#include <sys/types.h>
#include <sys/wait.h>
#include <signal.h>
#include <fcntl.h>


void display_prompt()
{
    printf("%s", "CodeWar > ");
    fflush(stdout);
}

int history(char ** bash){
    int fd;
    fd = open("history", O_RDWR | O_CREAT, 0777);
    if (fd == -1){
        perror("Open_history");
        return -1;
    }
    write(fd, strcat(*bash, "\n"), 20);
    return 0;
}

void run_commande(CPU * grid)
{
    int nb, status, flag, pid;
    char ***bash;

    bash = ligne_commande(&flag, &nb);
    if (bash == NULL){
        return;
    }

    pid = fork();
    if (pid == -1){
        perror("fork");
        return;
    }
    if (pid == 0){
        if (nb <= 1){
            commande(bash[0], grid, pid);
            history(bash[0]);
        }
        else{
            printf("One command for a line\n");
        }
    }
    else
    {
        if (flag == 0){
            waitpid(pid, &status, 0);
        }
        waitpid(pid, &status, pid);
        libere(bash);
    }
    waitpid(pid, &status, 1);
}

void commande(char ** tab, CPU * grid, int pid)
{
    char * option = tab[0];
    /* this option displays the grid */
    if (strcmp(option, "grid") == 0){
        display_grid(grid);
    }

    /* this option displays CPU */
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

    if (strcmp(option, "next") == 0){
        next();
    }
    /*this option display the list of the different commands available*/
    if ((strcmp(option, "help") == 0)){
        printf("\t\t\tWelcome in the CodeWar's manuel\n");
        printf("\t- the \"grid\" command displays the game's board\n");
        printf("\t- the \"cpu\" command, followed by the id of the CPU, displays the RAM and the registers of the CPU\n");
        printf("\t- the \"next\" command, increments the PC registers of all the CPU and go to the next instructions\n");
        printf("\t- the \"exit\" command, exit the game\n");
    }
    if (strcmp(option, "exit") == 0){
        if (kill(pid,SIGKILL)==-1) perror("kill_in_shell");
        exit(0);
    }
}
