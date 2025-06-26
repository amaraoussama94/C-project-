/** 
 * @file produit.c
 *
 * @brief fonctions de gestion des produits pour un système de gestion de stock.
 * Les opérations incluent l'ajout, l'affichage, la recherche, la modification et la suppression de produits.
 *
 * @author Oussama
 * @date 2024-06-09
 * @version 1.0
 */
// produit.c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "produit.h"

/**
 * @brief Ajoute un nouveau produit au fichier "stock.dat".
 *
 * Cette fonction demande à l'utilisateur de saisir les informations d'un produit
 * (nom, identifiant, quantité, prix), puis enregistre ces informations dans le fichier
 * binaire "stock.dat". Si le fichier ne peut pas être ouvert, un message d'erreur est affiché.
 *
 */
void ajouterProduit() {
    Produit p;
    FILE *f = fopen("stock.dat", "ab");
    if (!f) {
        perror("Erreur d'ouverture");
        return;
    }

    printf("\nNom : ");
    fgets(p.nom, sizeof(p.nom), stdin);
    p.nom[strcspn(p.nom, "\n")] = '\0'; // Supprime \n

    printf("ID : ");
    scanf("%d", &p.id);
    printf("Quantité : ");
    scanf("%d", &p.quantite);
    printf("Prix : ");
    scanf("%f", &p.prix);
    getchar(); // Vide le buffer stdin

    fwrite(&p, sizeof(Produit), 1, f);
    fclose(f);
    printf(" Produit ajouté !\n");
}

/**
 * @brief Affiche la liste des produits stockés dans le fichier "stock.dat".
 *
 * Cette fonction ouvre le fichier binaire "stock.dat" en mode lecture,
 * lit chaque structure Produit enregistrée, et affiche ses informations
 * (ID, nom, quantité, prix) sur la sortie standard. Si le fichier n'existe pas
 * ou ne peut pas être ouvert, un message d'erreur est affiché.
 *
 */

void afficherProduits() {
    Produit p;
    FILE *f = fopen("stock.dat", "rb");
    if (!f) {
        perror("Aucun stock à afficher");
        return;
    }

    printf("\n--- LISTE DES PRODUITS ---\n");
    while (fread(&p, sizeof(Produit), 1, f)) {
        printf("ID: %d | Nom: %s | Qté: %d | Prix: %.2f\n", p.id, p.nom, p.quantite, p.prix);
    }
    fclose(f);
}

/**
 * @brief Recherche un produit dans le fichier "stock.dat" par son nom et affiche ses informations si trouvé.
 *
 * Cette fonction demande à l'utilisateur de saisir le nom d'un produit, puis parcourt le fichier binaire "stock.dat"
 * pour rechercher un produit correspondant. Si le produit est trouvé, ses informations (ID, quantité, prix) sont affichées.
 * Si aucun produit n'est trouvé, un message approprié est affiché.
 *
 */

void chercherProduit() {
    Produit p;
    char nomRecherche[50];
    int found = 0;

    printf("Entrez le nom du produit : ");
    fgets(nomRecherche, sizeof(nomRecherche), stdin);
    nomRecherche[strcspn(nomRecherche, "\n")] = '\0';

    FILE *f = fopen("stock.dat", "rb");
    if (!f) {
        perror("Erreur de lecture");
        return;
    }

    while (fread(&p, sizeof(Produit), 1, f)) {
        if (strcmp(p.nom, nomRecherche) == 0) {
            printf(" Trouvé : ID %d, Qté %d, Prix %.2f\n", p.id, p.quantite, p.prix);
            found = 1;
        }
    }
    if (!found) printf(" Aucun produit trouvé.\n");

    fclose(f);
}

/**
 * @brief Modifie les informations d'un produit existant dans le fichier "stock.dat".
 *
 * Cette fonction recherche un produit par son identifiant (ID) dans le fichier binaire "stock.dat".
 * Si le produit est trouvé, elle permet à l'utilisateur de modifier le nom, la quantité et le prix du produit.
 * Les modifications sont enregistrées directement dans le fichier.
 *
 * Étapes principales :
 * 1. Demande à l'utilisateur l'ID du produit à modifier.
 * 2. Ouvre le fichier "stock.dat" en mode lecture/écriture binaire.
 * 3. Parcourt le fichier à la recherche du produit correspondant à l'ID.
 * 4. Si trouvé, demande les nouvelles informations et met à jour le produit dans le fichier.
 * 5. Affiche un message de confirmation ou d'erreur selon le résultat.
 *
 */

void modifierProduit() {
    Produit p;
    int idRecherche;
    int found = 0;

    printf("ID du produit à modifier : ");
    scanf("%d", &idRecherche);
    getchar();

    FILE *f = fopen("stock.dat", "rb+");
    if (!f) {
        perror("Erreur de lecture");
        return;
    }

    while (fread(&p, sizeof(Produit), 1, f)) {
        if (p.id == idRecherche) {
            printf("Nouveau nom : ");
            fgets(p.nom, sizeof(p.nom), stdin);
            p.nom[strcspn(p.nom, "\n")] = '\0';

            printf("Nouvelle quantité : ");
            scanf("%d", &p.quantite);
            printf("Nouveau prix : ");
            scanf("%f", &p.prix);
            getchar();

            fseek(f, -sizeof(Produit), SEEK_CUR);
            fwrite(&p, sizeof(Produit), 1, f);
            printf(" Produit modifié !\n");
            found = 1;
            break;
        }
    }

    if (!found) printf(" Produit non trouvé.\n");
    fclose(f);
}

/**
 * @brief Supprime un produit du fichier "stock.dat" en fonction de son identifiant.
 *
 * Cette fonction demande à l'utilisateur de saisir l'identifiant du produit à supprimer.
 * Elle lit ensuite tous les produits du fichier binaire "stock.dat" et copie ceux dont
 * l'identifiant est différent dans un fichier temporaire "temp.dat". Si le produit à
 * supprimer est trouvé, il n'est pas copié dans le fichier temporaire. À la fin de
 * l'opération, le fichier original est remplacé par le fichier temporaire.
 *
 * Affiche un message indiquant si le produit a été supprimé ou non trouvé.
 *
 */

void supprimerProduit() {
    Produit p;
    int idSupp;
    int found = 0;

    printf("ID à supprimer : ");
    scanf("%d", &idSupp);
    getchar();

    FILE *f = fopen("stock.dat", "rb");
    FILE *tmp = fopen("temp.dat", "wb");
    if (!f || !tmp) {
        perror("Erreur de fichiers");
        return;
    }

    while (fread(&p, sizeof(Produit), 1, f)) {
        if (p.id != idSupp) {
            fwrite(&p, sizeof(Produit), 1, tmp);
        } else {
            found = 1;
        }
    }

    fclose(f);
    fclose(tmp);

    remove("stock.dat");
    rename("temp.dat", "stock.dat");

    if (found) {
        printf(" Produit supprimé.\n");
    } else {
        printf(" Produit non trouvé.\n");
    }
}
