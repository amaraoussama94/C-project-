// main.c
#include <stdio.h>
#include <stdlib.h>
#include "produit.h"

int main() {
    int choix;

    do {
        printf("\n===== GESTION STOCK =====\n");
        printf("1. Ajouter produit\n");
        printf("2. Afficher produits\n");
        printf("3. Rechercher produit\n");
        printf("4. Modifier produit\n");
        printf("5. Supprimer produit\n");
        printf("0. Quitter\n");
        printf("Choix : ");
        scanf("%d", &choix);
        getchar();

        switch (choix) {
            case 1: ajouterProduit(); break;
            case 2: afficherProduits(); break;
            case 3: chercherProduit(); break;
            case 4: modifierProduit(); break;
            case 5: supprimerProduit(); break;
            case 0: printf(" À bientôt !\n"); break;
            default: printf(" Choix invalide.\n");
        }
    } while (choix != 0);

    return 0;
}
