/** 
 * @file produit.c
 *
 * @brief fonctions de gestion des produits pour un système de gestion de stock.
 * Les opérations incluent l'ajout, l'affichage, la recherche, la modification et la suppression de produits.
 *
 * @author Oussama
 * @date 2024-06-28
 * @version 2.0
 */
#include <stdio.h>
#include <stdlib.h>
#include "database.h"

void ajouter_produit_interactif(sqlite3 *db) {
    Produit p;
    printf("Nom : ");
    scanf("%99s", p.nom);
    printf("Quantité : ");
    scanf("%d", &p.quantite);
    printf("Prix : ");
    scanf("%f", &p.prix);

    if (db_ajouter_produit(db, &p) == 0)
        printf("Produit ajouté avec succès.\n");
    else
        printf("Erreur lors de l'ajout.\n");
}

void modifier_produit_interactif(sqlite3 *db) {
    Produit p;
    printf("ID du produit à modifier : ");
    scanf("%d", &p.id);
    printf("Nouveau nom : ");
    scanf("%99s", p.nom);
    printf("Nouvelle quantité : ");
    scanf("%d", &p.quantite);
    printf("Nouveau prix : ");
    scanf("%f", &p.prix);

    if (db_modifier_produit(db, &p) == 0)
        printf("Produit modifié avec succès.\n");
    else
        printf("Erreur lors de la modification.\n");
}

void supprimer_produit_interactif(sqlite3 *db) {
    int id;
    printf("ID du produit à supprimer : ");
    scanf("%d", &id);

    if (db_supprimer_produit(db, id) == 0)
        printf("Produit supprimé.\n");
    else
        printf("Erreur lors de la suppression.\n");
}

void lister_produits_interactif(sqlite3 *db) {
    if (db_lister_produits(db) != 0)
        printf("Erreur lors de l'affichage des produits.\n");
}
