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
#include "produit.h"

/**
 * @brief Vérifie si un produit avec le nom donné existe dans la base de données.
 *
 * Cette fonction interroge la base de données pour vérifier si un produit
 * avec le nom spécifié existe déjà. Elle retourne 1 si le produit existe,
 * 0 sinon.
 *
 * @param db Pointeur vers la base de données SQLite.
 * @param nom Nom du produit à vérifier.
 * @return 1 si le produit existe, 0 sinon.
 */
int db_produit_existe(sqlite3 *db, const char *nom) {
    const char *sql = "SELECT COUNT(*) FROM produits WHERE nom = ?";
    sqlite3_stmt *stmt;
    int existe = 0;
// Préparation de la requête SQL
    if (sqlite3_prepare_v2(db, sql, -1, &stmt, NULL) != SQLITE_OK)
        return 0;
// Liaison du paramètre
    sqlite3_bind_text(stmt, 1, nom, -1, SQLITE_STATIC);
// Exécution de la requête
    if (sqlite3_step(stmt) == SQLITE_ROW) {
        existe = sqlite3_column_int(stmt, 0) > 0;
    }
// Libération des ressources
    sqlite3_finalize(stmt);
    return existe;
}

/**
 * @brief Adds a new product to the database interactively.
 *
 * Prompts the user for product details and inserts the new product into the database.
 *
 * @param db Pointer to the SQLite database connection.
 */
void ajouter_produit_interactif(sqlite3 *db) {
    Produit p;
    printf("Nom : ");
    scanf("%99s", p.nom);

    // Vérification d'existence
    if (db_produit_existe(db, p.nom)) {
        printf("Le produit  existe déjà. voulez-vous le modifier via menu modifier ");
        return;
    }

    // Si le produit n'existe pas, on continue l'ajout
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
