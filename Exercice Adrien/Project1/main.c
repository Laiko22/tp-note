//NOTE : 8/20

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define taillemax 9 // pas vu en cours

int taille;
int grille[taillemax][taillemax] = { 0 };   // on evite les variables globales
int niveau;
int complete = 0;


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
}

void grilleComplete() {
    complete = 1;
    for (int i = 0; i < taille; i++) {
        for (int j = 0; j < taille; j++) {
            if (grille[i][j] == 0) {
                complete = 0;
                return;
            }
        }
    }
    if (complete) {
        printf("Felicitation ! Vous avez rempli toute la grille.\n");
    }
}

void initialisergrille() {

    int ligne, colonne, valeur;
    int fin = 0;

    grilleComplete();
    if (complete) {
        printf("La grille est deja complete !\n");
        return;
    }

        printf("Quelle valeur voulez-vous entrer dans votre tableau : ");
        scanf_s("%d", &valeur); // on est censé limiter la valeur à la taille du tableau
        printf("A quelle ligne voulez-vous assigner votre valeur (1 a %d) : ", taille);
        scanf_s("%d", &ligne);
        printf("A quelle colonne voulez-vous assigner votre valeur (1 a %d) : ", taille);
        scanf_s("%d", &colonne);

        if (ligne < 1 || ligne > taille || colonne < 1 || colonne > taille) {
            printf("Valeurs incoherentes, veuillez recommencer.\n");
            return;
        }

        int deja = 0;

        for (int i = 0; i < taille; i++) {
            if (grille[ligne - 1][i] == valeur) {
                deja = 1;
                printf("Erreur : le nombre %d existe deja dans la ligne %d.\n", valeur, ligne);
                break;
            }
            if (grille[i][colonne - 1] == valeur) {
                deja = 1;
                printf("Erreur : le nombre %d existe deja dans la colonne %d.\n", valeur, colonne);
                break;
            }
        }

        if (deja) 
            return;
        

        grille[ligne - 1][colonne - 1] = valeur;
        printf("Valeur %d ajoutée à la position (%d, %d).\n", valeur, ligne, colonne);
       
}

void affichage() {
    for (int i = 0; i < taille; i++) {
        printf("----");
    }
    printf("-\n");

    for (int i = 0; i < taille; i++) {
        for (int j = 0; j < taille; j++) {
            if (grille[i][j] == 0)
                printf("|   ");
            else
                printf("| %d ", grille[i][j]);
        }
        printf("|\n");

        for (int j = 0; j < taille; j++) {
            printf("----");
        }
        printf("-\n");
    }
}

void afficherMenu() {
    printf("\n=== MENU ===\n");
    printf("1. Choisir la taille de la grille\n");
    printf("2. Ajouter un nombre a la grille\n");
    printf("3. Generer la grille aleatoirement\n");
    printf("4. Afficher la grille\n");
    printf("5. Quitter\n");
    printf("Choisissez une option : ");
}

int main() {
    int choix;
    int quitter = 0;

    while (!quitter) {
        afficherMenu();
        scanf_s("%d", &choix);

        switch (choix) {
        case 1:
            taillegrille();
            break;
        case 2:
            initialisergrille();
            break;
        case 3:
            aleatoire();
            break;
        case 4:
            affichage();
            break;
        case 5:
            printf("Au revoir!\n");
            quitter = 1;
            break;
        default:
            printf("Option invalide. Veuillez reessayer.\n");
            break;
        }
       
    }
      
    return 0;
}
