// produit.c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "produit.h"

// Ajouter un nouveau produit
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

// Affiche tous les produits du fichier
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

// Recherche un produit par nom
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

// Modifie un produit existant (par ID)
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

// Supprime un produit (recopie sans le produit ciblé)
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
