// produit.h
#ifndef PRODUIT_H
#define PRODUIT_H

// Structure représentant un produit
typedef struct {
    int id;
    char nom[50];
    int quantite;
    float prix;
} Produit;

// Déclarations des fonctions
void ajouterProduit();
void afficherProduits();
void modifierProduit();
void supprimerProduit();
void chercherProduit();

#endif
