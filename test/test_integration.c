/**
 * @file test/test_integration.c
 * @brief Test d'intégration pour les fonctions de gestion de la base de données.
 *  Ce fichier teste le cycle complet d'ajout, de modification et de suppression d'un produit.
 *  @author Oussama Amara
 * @date 2025-06-28
 * @version 1.0
 */
#include <assert.h>
#include <stdio.h>
#include <string.h>
#include "database.h"
#include "produit.h"

/**
 * @brief Teste le cycle complet d'ajout, de modification et de suppression d'un produit.
 * @param db Pointeur vers la base de données SQLite.
 * @return void
 */
void test_cycle(sqlite3 *db) {
    Produit p = {.quantite = 5, .prix = 3.14};
    strcpy(p.nom, "IntegrationTest");

    // Add
    assert(db_ajouter_produit(db, &p) == 0);
    assert(db_produit_existe(db, "IntegrationTest") == 1);

    // Modify
    p.id = 1;
    strcpy(p.nom, "IntegrationTestMod");
    p.quantite = 10;
    p.prix = 9.99;
    assert(db_modifier_produit(db, &p) == 0);

    // Delete
    assert(db_supprimer_produit(db, p.id) == 0);
    assert(db_produit_existe_par_id(db, p.id) == 0);
}

/**
 * @brief Fonction principale pour exécuter les tests d'intégration.
 * @return 0 si tous les tests réussissent, sinon un code d'erreur.
 */
int main() {
    //Force l'encodage UTF-8 dans le terminal Windows
    #ifdef _WIN32
        system("chcp 65001 > nul");
    #endif
    sqlite3 *db;
    assert(db_init(&db, ":memory:") == 0);
    test_cycle(db);
    db_close(db);
    printf("Test d'intégration réussi.\n");
    return 0;
}
