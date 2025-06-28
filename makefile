#Définit le compilateur utilisé (ici GCC).
CC=gcc

# Définit la version du programme.
BIN=gestion_stock_v$(VERSION)

#Options de compilation :
#-Wall et -Wextra activent de nombreux avertissements utiles pour repérer les erreurs potentielles.
#-g ajoute les symboles de débogage (utile avec GDB, par exemple).
#-I ajoute le dossier "Inc" au chemin de recherche des fichiers d'en-tête.
CFLAGS=-Wall -Wextra -g -IInc

#Liste des fichiers source principaux et supplémentaires.
SRC=$(SRC_MAIN) $(SRC_SRC) $(SRC_SQLITE)
#SRC_MAIN est le fichier principal (main.c).
SRC_MAIN=main.c
#SRC_SRC contient tous les fichiers .c du dossier src.
SRC_SRC=$(wildcard Src/*.c)
#Ajoute le fichier SQLite3 source.
SRC_SQLITE = sqlite-lib/sqlite3.c

#Convertit la liste de fichiers .c en fichiers .o (les objets intermédiaires).
OBJ=$(SRC:.c=.o)

# Nom de l’exécutable final.
# Si le dossier build n'existe pas, il sera créé automatiquement.
EXEC=build/gestion_stock.exe

#Cible par défaut : si tu tapes make, cela va construire l’exécutable.
all: $(EXEC)

#Crée l’exécutable à partir des fichiers .o.
#$@ = le nom de la cible (gestion_stock.exe)
#$^ = tous les fichiers .o (dépendances)
$(EXEC): $(OBJ)
	@if not exist build mkdir build
	@echo "Compilation de l'exécutable $(EXEC)..."
	$(CC) $(CFLAGS) -o $@ $^

#Compile chaque fichier .c individuellement en .o.
#$< = le fichier source .c
#$@ = le fichier .o généré
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

#Supprime les fichiers .o et l’exécutable .exe (Windows utilise del au lieu de rm).
clean:
	@echo "Nettoyage des fichiers objets et exécutables..."
	@del /S /Q *.o 2>nul || exit 0
	@del /S /Q *.exe 2>nul || exit 0
	@if exist build rmdir /S /Q build

#Compile et lance ton programme en une seule commande : make run
run: all
	$(EXEC)
# CI build with embedded version macro and versioned binary
ci-build:
	@if not exist build mkdir build
	$(CC) $(CFLAGS) -DVERSION=\"$(VERSION)\" -o gestion_stock_v$(VERSION) $(SRC)
