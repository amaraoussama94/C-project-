# 📦 Projet C - Gestion de Stock

Ce projet est une application en langage **C** permettant la gestion simple et efficace d’un stock de produits via des fichiers texte. Il s'agit d'une base pour des systèmes de gestion plus avancés.

## 🎯 Objectifs

Gérer un ensemble de produits avec leurs informations clés : ID, nom, quantité, prix

Permettre l’ajout, la suppression, la modification et l’affichage des produits via une interface console

Assurer la persistance des données à l’aide d’une base SQLite3 embarquée (plus de fichiers plats)

Illustrer la structuration modulaire d’un projet C avec :

    séparation des responsabilités (database, produit, main)

    compilation automatisée via Makefile

    documentation générée avec Doxygen

## 🛠️ Structure du projet

gestion_stock_c/

├── Inc/              # Fichiers d'en-tête (.h)

│   ├── database.h

│   ├── produit.h

│   └── sqlite3.h

├── Src/              # Fichiers source (.c)

│   ├── main.c

│   ├── database.c

│   └── produit.c

├── sqlite-lib/       # SQLite3 embarqué

│   └── sqlite3.c

├── build/            # Fichiers compilés (.exe)

├── doc/              # Documentation Doxygen

├── Makefile

├── Doxyfile

└── README.md


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

Assurez-vous d’avoir gcc et make installés (via MinGW ou MSYS2).

make        # Compile le projet
make run    # Compile et exécute
make clean  # Supprime les fichiers générés

## 🔧 Auto Build Process

This project leverages an automated build pipeline to ensure every change is compiled, tested, and deployed efficiently. Here’s how it works:

1. **Trigger**: The build process is automatically triggered by a push to the `main` branch or upon the creation of a pull request.
2. **Build Environment**: A pre-configured virtual environment installs all necessary dependencies as specified in `requirements.txt` or `environment.yml`.
3. **Validation & Tests**: Linting and unit tests are run to catch errors early and maintain code quality.
4. **Build & Package**: The application is compiled (if necessary) and bundled for deployment.
5. **Deploy (Optional)**: If the build passes, the code is deployed to the specified environment (e.g. GitHub Pages, Docker Hub, or a cloud platform).

All steps are defined in the `.github/workflows` directory using YAML configuration files. Comments within those files explain each stage of the pipeline.



