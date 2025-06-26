/**
 * @file fichier.h
 * @brief Déclarations des fonctions pour la gestion de la persistance des produits.
 *
 * Ce fichier contient les prototypes des fonctions permettant de charger et sauvegarder
 * les produits depuis/vers un fichier.
 * @author Oussama
 * @date 2024-06-09
 * @version 1.0
 */

#ifndef FICHIER_H
#define FICHIER_H

#include "produit.h"


 /**
    * @brief Charge tous les produits du fichier dans un tableau.
    * 
    * @param tableau Pointeur vers le tableau de produits à remplir.
    * @param tailleMax Nombre maximal de produits à charger.
    * @return Le nombre de produits effectivement chargés, ou -1 en cas d'erreur.
    */
int chargerProduits(Produit *tableau, int tailleMax);

 /**
    * @brief Sauvegarde tous les produits à partir d'un tableau dans un fichier.
    * 
    * @param tableau Pointeur vers le tableau de produits à sauvegarder.
    * @param taille Nombre de produits à sauvegarder.
    */
   
void sauvegarderProduits(Produit *tableau, int taille);

#endif
