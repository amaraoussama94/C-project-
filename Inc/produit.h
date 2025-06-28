/**
 * @file produit.h
 * @brief Interface utilisateur pour la gestion interactive des produits.
 * 
 * @author Oussama
 * @date 2024-06-28
 * @version 2.0
 */


#ifndef PRODUIT_H
#define PRODUIT_H

#include <sqlite3.h>
#include "database.h"
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
int db_produit_existe(sqlite3 *db, const char *nom) ;
/**
 * @brief Demande à l'utilisateur les informations d'un produit et l'ajoute à la base.
 * 
 * @param db Pointeur vers la base de données SQLite.
 */
void ajouter_produit_interactif(sqlite3 *db);

/**
 * @brief Demande à l'utilisateur un ID et les nouvelles infos, puis modifie le produit.
 * 
 * @param db Pointeur vers la base de données SQLite.
 */
void modifier_produit_interactif(sqlite3 *db);

/**
 * @brief Demande à l'utilisateur un ID et supprime le produit correspondant.
 * 
 * @param db Pointeur vers la base de données SQLite.
 */
void supprimer_produit_interactif(sqlite3 *db);

/**
 * @brief Affiche tous les produits de la base de données.
 * 
 * @param db Pointeur vers la base de données SQLite.
 */
void lister_produits_interactif(sqlite3 *db);

#endif

