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

- Ajout, suppression et modification de produits
- Gestion des quantités et des prix
- Sauvegarde des données via SQLite3
- Interface console simple et efficace
- Compilation multiplateforme (Linux & Windows)

## 🔄 Changements récents (Branche `dev_RefactorSqlite`)

> Cette branche marque une refonte complète du projet pour le rendre plus modulaire, maintenable et professionnel.

### 🧠 Architecture & Refactorisation
- Suppression de l’ancienne logique basée sur fichiers plats (`fichier.c`, `fichier.h`)
- Intégration d’un module `database.c` utilisant **SQLite3** pour la persistance des données
- Création d’un module `produit.c` dédié à l’interface utilisateur (saisie, affichage)
- Séparation claire des responsabilités entre `main`, `produit`, et `database`

### 🗂️ Réorganisation du projet
- Nouvelle structure modulaire :
Inc/ → fichiers .h Src/ → fichiers .c sqlite-lib/ → sqlite3.c embarqué build/ → fichiers compilés

- Mise à jour du `Makefile` :
- Compatible Windows (sans `-p`)
- Nettoyage récursif avec `make clean`
- Exécutable généré dans `build/`

### 🧪 Fonctionnalités améliorées
- Toutes les opérations (ajout, suppression, modification, affichage) passent par SQLite
- Plus de dépendance à des fichiers texte ou binaires
- Interface console plus robuste et modulaire

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

## ⚙️ Intégration Continue
Ce projet utilise GitHub Actions pour :

Compiler automatiquement les binaires Linux et Windows

Générer un tag Git (PROD_VERSION_x.xx)

Publier les binaires dans les Releases GitHub

Uploader les artefacts dans l’onglet Actions

##Téléchargement des binaires
Les dernières versions compilées sont disponibles ici :

👉 [Voir les Releases](https://github.com/amaraoussama94/gestion_stock_c/releases)




