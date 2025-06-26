// fichier.h
#ifndef FICHIER_H
#define FICHIER_H

#include "produit.h"

// Charge tous les produits du fichier dans un tableau
int chargerProduits(Produit *tableau, int tailleMax);

// Sauvegarde tous les produits à partir d'un tableau
void sauvegarderProduits(Produit *tableau, int taille);

#endif
