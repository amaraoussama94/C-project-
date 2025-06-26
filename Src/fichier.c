/**
 * @file fichier.c
 * @brief Fonctions pour la gestion de la sauvegarde et du chargement des produits dans
 * un fichier binaire.
 * @author Oussama
 * @date 2024-06-09
 * @version 1.0
 */
#include <stdio.h>
#include "fichier.h"

 /**
    * @brief Charge les produits depuis le fichier binaire "stock.dat" dans un tableau.
    *
    * Cette fonction ouvre le fichier "stock.dat" en mode binaire lecture ("rb") et lit
    * les produits un à un pour les stocker dans le tableau passé en paramètre.
    *
    * @param tableau Pointeur vers le tableau de produits à remplir.
    * @param tailleMax Nombre maximal d'éléments à charger dans le tableau.
    * @return Le nombre d'éléments effectivement chargés dans le tableau.
    */

int chargerProduits(Produit *tableau, int tailleMax) {
    FILE *f = fopen("stock.dat", "rb");
    if (!f) return 0;

    int i = 0;
    while (i < tailleMax && fread(&tableau[i], sizeof(Produit), 1, f)) {
        i++;
    }

    fclose(f);
    return i;  // Nombre d'éléments chargés
}

 /**
    * @brief Sauvegarde tous les produits d'un tableau dans le fichier binaire "stock.dat".
    *
    * Cette fonction ouvre le fichier "stock.dat" en mode binaire écriture ("wb") et écrit
    * tous les produits du tableau dans le fichier.
    *
    * @param tableau Pointeur vers le tableau de produits à sauvegarder.
    * @param taille Nombre d'éléments à sauvegarder dans le fichier.
    */
void sauvegarderProduits(Produit *tableau, int taille) {
    FILE *f = fopen("stock.dat", "wb");
    if (!f) return;

    for (int i = 0; i < taille; i++) {
        fwrite(&tableau[i], sizeof(Produit), 1, f);
    }

    fclose(f);
}
