# 📦 Projet C - Gestion de Stock

Ce projet est une application en langage **C** permettant la gestion simple et efficace d’un stock de produits via des fichiers texte. Il s'agit d'une base pour des systèmes de gestion plus avancés.

## 🎯 Objectifs

- Gérer un ensemble de produits avec leurs informations clés (ID, nom, quantité, prix)
- Permettre l’ajout, la suppression, la modification et l’affichage des produits
- Sauvegarder les produits dans un fichier local pour assurer la persistance des données
- Servir d’introduction à la structuration de projets C modulaires avec `Makefile` et documentation

## 🛠️ Structure du projet

C-project-/ 

│ 

├── main.c # Point d'entrée du programme 

├──src/
    ├──produit.c  # Logique métier pour gérer les produits 

    ├── fichier.c # Lecture et écriture des produits sur fichier 
├──Inc/ 
    ├──produit.h # Logique métier pour gérer les produits 

    ├── fichier.h # Lecture et écriture des produits sur fichier    

├── Makefile # Script de compilation 

└── README.md # Documentation du projet


## ✨ Fonctionnalités principales

- Ajouter un produit
- Afficher la liste des produits
- Rechercher un produit par ID
- Supprimer ou modifier un produit existant
- Persistance des données dans un fichier structuré

## 🔄 Changements récents (Branche `dev_Refactorcode`)

- Refactorisation complète du code source : séparation `.c` / `.h`
- Ajout de commentaires **Doxygen** professionnels dans tous les fichiers
- Nettoyage du `Makefile` et ajout de règles plus propres
- Préparation d'une documentation automatique via Doxygen

## 🚀 Compilation

### Pré-requis
- Compilateur C (`gcc`)
- [Doxygen (optionnel)](https://www.doxygen.nl/)
- Système compatible POSIX ou Windows avec MinGW

### Instructions

```bash
make
./gestion_stock
