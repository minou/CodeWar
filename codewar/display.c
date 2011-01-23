#include <stdio.h>
#include "struct.h"

#define NB_LIGNES 16
#define NB_COLONNES 16

/* Méthode permettant d'afficher le plateau */
void display_grid(CPU grid[256])
{
    int ligne, colonne;
    int nb_lignes = NB_LIGNES;
    int nb_colonnes = NB_COLONNES;

    for (ligne = 0; ligne < nb_lignes; ligne++)
    {
        for (colonne = 0; colonne < nb_colonnes; colonne++)
        {
        }
        if (ligne < 10)
        {
            printf("%d  ", ligne);
        }
        else
        {
            printf("%d ", ligne);
        }
        printf("\n");
    }
}
