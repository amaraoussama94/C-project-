/**
 * @file main.c
 * @brief  Ce programme permet à l'utilisateur d'ajouter, modifier, 
 * supprimer et lister des produits dans une base de données SQLite.
 * Il utilise une interface en ligne de commande pour interagir avec l'utilisateur.
 * 
 * @author Oussama
 * @date 2024-06-28
 * @version 2.0
 */

#include <stdio.h>
#include "database.h"


/**
 * @brief Adds a new product to the database interactively.
 * 
 * Prompts the user for product details and inserts the new product into the database.
 * 
 * @param db Pointer to the SQLite database connection.
 */
void ajouter_produit_interactif(sqlite3 *db);

/**
 * @brief Modifies an existing product in the database interactively.
 * 
 * Prompts the user to select and update product details in the database.
 * 
 * @param db Pointer to the SQLite database connection.
 */
void modifier_produit_interactif(sqlite3 *db);
 

/**
 * @brief Deletes a product from the database interactively.
 * 
 * Prompts the user to select a product to remove from the database.
 * 
 * @param db Pointer to the SQLite database connection.
 */
void supprimer_produit_interactif(sqlite3 *db);


/**
 * @brief Lists all products in the database interactively.
 * 
 * Retrieves and displays all products stored in the database.
 * 
 * @param db Pointer to the SQLite database connection.
 */
void lister_produits_interactif(sqlite3 *db);

/**
 * @brief Displays the main menu for the stock management system.
 * 
 * Shows options for adding, listing, deleting, and modifying products,
 * as well as an option to exit the program.
 */
void afficher_menu() {
    printf("\n=== Gestion de Stock ===\n");
    printf("1. Ajouter un produit\n");
    printf("2. Lister les produits\n");
    printf("3. Supprimer un produit\n");
    printf("4. Modifier un produit\n");
    printf("0. Quitter\n");
    printf("Choix : ");
}

int main() {
    sqlite3 *db;
    // Initialisation de la base de données
    if (db_init(&db, "stock.db") != 0) {
        fprintf(stderr, "Impossible d'initialiser la base de données.\n");
        return 1;
    }

    int choix;
    // Boucle principale du menu
    do {
        afficher_menu();
        scanf("%d", &choix);
        getchar(); // consommer le \n

        switch (choix) {
            case 1:
                ajouter_produit_interactif(db);
                break;
            case 2:
                lister_produits_interactif(db);
                break;
            case 3:
                supprimer_produit_interactif(db);
                break;
            case 4:
                modifier_produit_interactif(db);
                break;
            case 0:
                printf("Au revoir !\n");
                break;
            default:
                printf("Choix invalide.\n");
        }
    } while (choix != 0);

    db_close(db);
    return 0;
}

