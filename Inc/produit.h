 /** 
 * @file produit.h
 * @brief Déclarations des fonctions pour la gestion des produits en stock.
 *
 * Ce fichier contient les prototypes des fonctions permettant d'ajouter, d'afficher,
 * de modifier, de supprimer et de chercher des produits dans le stock.
 * Il définit également la structure de données représentant un produit.
 *
 * @author Oussama
 * @date 2024-06-09
 * @version 1.0
 */
#ifndef PRODUIT_H
#define PRODUIT_H

/**
 * @struct Produit
 * @brief Structure représentant un produit en stock.
 *
 * Cette structure contient les informations relatives à un produit,
 * telles que son identifiant, son nom, sa quantité disponible et son prix.
 *
 * @var Produit::id
 * Identifiant unique du produit.
 *
 * @var Produit::nom
 * Nom du produit (chaîne de caractères de taille maximale 50).
 *
 * @var Produit::quantite
 * Quantité disponible du produit en stock.
 *
 * @var Produit::prix
 * Prix unitaire du produit.
 */
typedef struct {
    int id;
    char nom[50];
    int quantite;
    float prix;
} Produit;


/**
 * @brief Ajoute un nouveau produit à la collection de produits.
 *
 * Cette fonction permet à l'utilisateur de saisir les informations nécessaires
 * pour créer et ajouter un nouveau produit à la liste ou base de données des produits.
 * Elle peut inclure la saisie du nom, du prix, de la quantité, etc.
 *
 */
void ajouterProduit();

/**
 * @brief Affiche la liste des produits disponibles.
 *
 * Cette fonction affiche à l'écran les informations concernant tous les produits.
 * Elle ne prend aucun paramètre et ne retourne aucune valeur.
 */
void afficherProduits();

/**
 * @brief Modifie les informations d'un produit existant.
 *
 * Cette fonction permet à l'utilisateur de modifier les détails d'un produit
 * déjà enregistré, comme son nom, sa quantité ou son prix, en fonction de son identifiant.
 */
void modifierProduit();

/**
 * @brief Supprime un produit de la collection.
 *
 * Cette fonction permet à l'utilisateur de supprimer un produit spécifique
 * en fonction de son identifiant. Elle demande confirmation avant de procéder
 * à la suppression.
 */
void supprimerProduit();

/**
 * @brief Recherche un produit par son nom.
 *
 * Cette fonction permet à l'utilisateur de rechercher un produit spécifique
 * en saisissant son nom. Si le produit est trouvé, ses informations sont affichées.
 */
void chercherProduit();

#endif
