#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define taillemax 9

int taille;
int colonne = 0;
int ligne = 0;
int valeur = 0;
int grille[taillemax][taillemax] = { 0 };
int verif = 0;
int niveau;

void aleatoire() {
    int totalCases = taille * taille;
    int casesremplir;

    printf("Entrer le niveau de difficulte voulu (1-3) : ");
    scanf_s("%d", &niveau);

    if (niveau < 1 || niveau > 3) {
        printf("Niveau invalide.\n");
        return;
    }

    switch (niveau) {
    case 1:
        casesremplir = totalCases / 2;
        break;
    case 2:
        casesremplir = totalCases / 3;
        break;
    case 3:
        casesremplir = totalCases / 4;
        break;
    }

    srand((unsigned int)time(NULL));
    int remplissage = 0;

    while (remplissage < casesremplir) {
        int ligne = rand() % taille;
        int colonne = rand() % taille;
        int valeur = (rand() % taille) + 1;

        if (grille[ligne][colonne] == 0) {
            int deja = 0;

            for (int i = 0; i < taille; i++) {
                if (grille[ligne][i] == valeur || grille[i][colonne] == valeur) {
                    deja = 1;
                    break;
                }
            }

            if (!deja) {
                grille[ligne][colonne] = valeur;
                remplissage++;
            }
        }
    }
}

void taillegrille() {
    printf("Entrer la taille de votre grille (max %d) : ", taillemax);
    scanf_s("%d", &taille);

    if (taille < 1 || taille > taillemax) {
        printf("La taille de la grille est invalide (entre 1 et %d).\n", taillemax);
        return;
    }

    printf("Quelle valeur voulez-vous entrer dans votre tableau : ");
    scanf_s("%d", &valeur);
    printf("A quelle ligne voulez-vous assigner votre valeur (1 a %d) : ", taille);
    scanf_s("%d", &ligne);
    printf("A quelle colonne voulez-vous assigner votre valeur (1 a %d) : ", taille);
    scanf_s("%d", &colonne);

    if (ligne >= 1 && ligne <= taille && colonne >= 1 && colonne <= taille) {
        grille[ligne - 1][colonne - 1] = valeur;
    }
    else {
        printf("Valeurs incohérentes, veuillez recommencer.\n");
    }
}

void verification() {
    for (int i = 0; i < taille; i++) {
        int valeursligne[taillemax] = { 0 };

        for (int j = 0; j < taille; j++) {
            if (grille[i][j] > 0) {
                if (valeursligne[grille[i][j] - 1] == 1) {
                    printf("Erreur : La valeur %d est repetee a la ligne %d\n", grille[i][j], i + 1);
                }
                else {
                    valeursligne[grille[i][j] - 1] = 1;
                }
            }
        }
    }
}

void affichage() {

    for (int i = 0; i < taille; i++) 

        printf("----");

    printf("-\n");

    for (int i = 0; i < taille; i++) {
        for (int j = 0; j < taille; j++) {
            if (grille[i][j] == 0)
                printf("|   ");
            else
                printf("| %d ", grille[i][j]);
        }
        printf("|\n");

        for (int j = 0; j < taille; j++) 

            printf("----");
        
        printf("-\n");
    }
}

int main() {

    taillegrille();
    aleatoire();
    verification();
    affichage();

    return 0;
}
