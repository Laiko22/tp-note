//Adrien Gillet

#include <stdio.h>

int taillemax = 9;
int taille;

void taillegrille() {
    
    printf("Entrer la taille de votre grille : ");
    scanf_s("%d", &taille);

    if (taille > taillemax) {
        printf("La taille de la grille est trop grande (max 9)\n");
    }
    else {
        for (int i = 0; i < taille; i++) { 

            printf("\n");

            for (int j = 0; j < taille; j++) {
                printf("| 0 ");
            }

            printf("|");
        }
    }
}

int main() {

    taillegrille();

    return 0;
}

