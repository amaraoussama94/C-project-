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

/**
 * @brief Clears the terminal screen.
 *
 * This function clears the console screen using the appropriate system command
 * depending on the operating system. On Windows systems, it uses "cls", while
 * on other systems (e.g., Linux, macOS), it uses "clear".
 *
 * @note This function relies on the system() call, which may have security implications.
 */
void clear_screen() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

/**
 * @brief Pauses the console and waits for the user to press a key before continuing.
 *
 * This function displays a prompt message asking the user to press any key to return to the menu.
 * It uses platform-specific commands to wait for a key press:
 * - On Windows systems, it uses the "pause" command with output redirected to null.
 * - On other systems (e.g., Linux, macOS), it uses the "read" command to wait for a single key press.
 */
void pause_console() {
    printf("\nAppuyez sur une touche pour revenir au menu...");
#ifdef _WIN32
    system("pause > nul");
#else
    system("read -n 1 -s -r");
#endif
}

int main() {
    //Force l'encodage UTF-8 dans le terminal Windows
    #ifdef _WIN32
        system("chcp 65001 > nul");
    #endif
    sqlite3 *db;
    // Initialisation de la base de données
    if (db_init(&db, "stock.db") != 0) {
        fprintf(stderr, "Impossible d'initialiser la base de données.\n");
        return 1;
    }

    int choix;
    // Boucle principale du menu
    do {
        clear_screen(); // ← Efface l'écran à chaque itération du menu
        afficher_menu();
        scanf("%d", &choix);
        getchar(); // consommer le \n

        switch (choix) {
            case 1:
                clear_screen(); // Efface l'écran avant d'ajouter un produit
                ajouter_produit_interactif(db);
                break;
            case 2:
                clear_screen(); // Efface l'écran avant de lister les produits
                lister_produits_interactif(db);
                pause_console(); // Pause pour permettre à l'utilisateur de lire la liste
                break;
            case 3:
                clear_screen(); // Efface l'écran avant de supprimer un produit
                supprimer_produit_interactif(db);
                break;
            case 4:
                clear_screen(); // Efface l'écran avant de modifier un produit
                modifier_produit_interactif(db);
                break;
            case 0:
                clear_screen(); // Efface l'écran avant de quitter
                printf("Au revoir !\n");
                break;
            default:
                clear_screen(); // Efface l'écran avant d'afficher le message d'erreur
                printf("Choix invalide.\n");
        }
    } while (choix != 0);

    db_close(db);
    return 0;
}

