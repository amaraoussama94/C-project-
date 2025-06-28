/**
 * @file test/test_database.c
 * @brief Tests unitaires pour les fonctions de gestion de la base de données.  
 *   Ce fichier contient des tests pour les fonctions d'ajout, de modification et de suppression de produits.
 *   Il utilise une base de données SQLite en mémoire pour les tests.   
 * @author Oussama Amara
 * @date 2025-06-28
 * @aversion 1.0
 */
#include <assert.h>
#include <stdio.h>
#include <string.h>
#include "database.h"

/**
 * @brief Teste l'ajout d'un produit dans la base de données.
 * @param db Pointeur vers la base de données SQLite.
 * @return void
 */
void test_ajouter_produit(sqlite3 *db) {
    Produit p = {.quantite = 10, .prix = 5.5};
    strcpy(p.nom, "TestProduit");
    assert(db_ajouter_produit(db, &p) == 0);
    assert(db_produit_existe(db, "TestProduit") == 1);
}

/**
 * @brief Teste la modification d'un produit dans la base de données.
 * @param db Pointeur vers la base de données SQLite.
 * @return void
 */
void test_modifier_produit(sqlite3 *db) {
    Produit p = {.id = 1, .quantite = 20, .prix = 9.99};
    strcpy(p.nom, "ProduitModifie");
    assert(db_modifier_produit(db, &p) == 0);
}

/**
 * @brief Teste la suppression d'un produit dans la base de données.
 * @param db Pointeur vers la base de données SQLite.
 * @return void
 */
void test_supprimer_produit(sqlite3 *db) {
    assert(db_supprimer_produit(db, 1) == 0);
    assert(db_produit_existe_par_id(db, 1) == 0);
}

/**
 * @brief Fonction principale pour exécuter les tests.
 * @return 0 si tous les tests réussissent, sinon un code d'erreur.
 */
int main() {
        //Force l'encodage UTF-8 dans le terminal Windows
    #ifdef _WIN32
        system("chcp 65001 > nul");
    #endif
    sqlite3 *db;
    assert(db_init(&db, ":memory:") == 0); // Use in-memory DB for testing

    test_ajouter_produit(db);
    test_modifier_produit(db);
    test_supprimer_produit(db);

    db_close(db);
    printf(" Tous les tests ont réussi.\n");
    return 0;
}
