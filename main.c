/**
 * @file main.c
 * @brief Programme principal pour la gestion de stock de produits.
 *
 * Ce programme propose un menu interactif permettant à l'utilisateur de :
 *   1. Ajouter un produit au stock
 *   2. Afficher la liste des produits
 *   3. Rechercher un produit spécifique
 *   4. Modifier les informations d'un produit
 *   5. Supprimer un produit du stock
 *   0. Quitter l'application
 *
 * Les fonctionnalités sont implémentées dans les fonctions déclarées dans "produit.h".
 * L'utilisateur interagit avec le programme via la console.
 *
 * @author Oussama
 * @date 2024-06-09
 * @version 1.0
 */

#include <stdio.h>
#include <stdlib.h>
#include "produit.h"

#ifndef VERSION
#define VERSION "dev"
#endif

int main() {
    int choix;
    printf("Gestion Stock - Version %s\n", VERSION);
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
