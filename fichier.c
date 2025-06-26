// fichier.c
#include <stdio.h>
#include "fichier.h"

// Charge les produits du fichier binaire dans un tableau
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

// Sauvegarde tous les produits à partir d'un tableau
void sauvegarderProduits(Produit *tableau, int taille) {
    FILE *f = fopen("stock.dat", "wb");
    if (!f) return;

    for (int i = 0; i < taille; i++) {
        fwrite(&tableau[i], sizeof(Produit), 1, f);
    }

    fclose(f);
}
