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

/**
 * @brief Interactively adds a new product to the database.
 *
 * Prompts the user to enter the product's name, quantity, and price via standard input,
 * then attempts to add the product to the database using db_ajouter_produit().
 * Displays a success or error message based on the result.
 *
 * @param db Pointer to the opened SQLite database connection.
 */
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

/**
 * @brief Interactively modifies the details of a product in the database.
 *
 * Prompts the user to enter the ID of the product to modify, then asks for the new
 * name, quantity, and price. Updates the product in the database using the provided
 * information. Displays a success or error message based on the outcome.
 *
 * @param db Pointer to the opened SQLite database connection.
 */
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

/**
 * @brief Supprime un produit de la base de données de manière interactive.
 *
 * Cette fonction demande à l'utilisateur de saisir l'identifiant (ID) du produit à supprimer,
 * puis appelle la fonction db_supprimer_produit pour effectuer la suppression dans la base de données SQLite.
 * Elle affiche un message indiquant si la suppression a réussi ou échoué.
 *
 * @param db Pointeur vers la base de données SQLite ouverte.
 */
void supprimer_produit_interactif(sqlite3 *db) {
    int id;
    printf("ID du produit à supprimer : ");
    scanf("%d", &id);

    if (db_supprimer_produit(db, id) == 0)
        printf("Produit supprimé.\n");
    else
        printf("Erreur lors de la suppression.\n");
}

/**
 * @brief Affiche la liste des produits de manière interactive.
 *
 * Cette fonction appelle db_lister_produits pour afficher tous les produits
 * présents dans la base de données SQLite passée en paramètre. Si une erreur
 * survient lors de l'affichage, un message d'erreur est affiché à l'utilisateur.
 *
 * @param db Pointeur vers la base de données SQLite.
 */
void lister_produits_interactif(sqlite3 *db) {
    if (db_lister_produits(db) != 0)
        printf("Erreur lors de l'affichage des produits.\n");
}
