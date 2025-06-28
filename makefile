# Makefile pour le projet de gestion de stock
# Ce Makefile compile le programme en C, gère les dépendances et crée un exécutable.
# Il est conçu pour être utilisé sur Windows, mais peut être adapté pour d'autres systèmes.

#Définit le compilateur utilisé (ici GCC).
# Check if the OS is Windows and set the compiler accordingly.
ifeq ($(OS),Windows_NT)
#local	build settings for Windows
 RM = del /S /Q
 RMDIR = rmdir /S /Q
 MKDIR = if not exist build mkdir build
 EXEC_EXT = .exe
 CC := gcc
else
#cross-platform settings
#used for github actions
 RM = rm -f
 RMDIR = rm -rf
 MKDIR = mkdir -p build
 EXEC_EXT =
 CC ?= gcc
endif

# Test sources and executable
TEST_SRC = test/test_database.c
TEST_EXEC = build/test_database$(EXEC_EXT)
# Définit la version du programme.
BIN = build/gestion_stock_v$(VERSION)$(EXEC_EXT)

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
EXEC=build/gestion_stock$(EXEC_EXT)

#	Fichiers de test d'intégration.
TEST_INTEGRATION_SRC = test/test_integration.c
TEST_INTEGRATION_EXEC = build/test_integration$(EXEC_EXT)
#Cible par défaut : si tu tapes make, cela va construire l’exécutable.
all: $(EXEC)

#Crée l’exécutable à partir des fichiers .o.
#MKDIR crée le dossier build s'il n'existe pas.
#$@ = le nom de la cible (gestion_stock.exe)
#$^ = tous les fichiers .o (dépendances)
$(EXEC): $(OBJ)
	@$(MKDIR)
	@echo "🔧 Compilation de $(EXEC)..."
	$(CC) $(CFLAGS) -o $@ $^

#Compile chaque fichier .c individuellement en .o.
#$< = le fichier source .c
#$@ = le fichier .o généré
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

#Cible pour nettoyer les fichiers intermédiaires et l'exécutable.
#support for Windows and Unix-like systems.
clean:
	@echo "Nettoyage..."
	-@$(RM) *.o
	-@$(RM) build/*$(EXEC_EXT)
	-@$(RMDIR) build

#Compile et lance ton programme en une seule commande : make run
run: all

	./$(EXEC)

# CI build with embedded version macro and versioned binary for linux
ci-build:
	@mkdir -p build
	$(CC) $(CFLAGS) -DVERSION=\"$(VERSION)\" -o build/gestion_stock_v$(VERSION) $(SRC)
	
# CI build for Windows with embedded version macro and versioned binary
ci-build-windows:
	@mkdir -p build
	x86_64-w64-mingw32-gcc $(CFLAGS) -DVERSION=\"$(VERSION)\" -o build/gestion_stock_v$(VERSION).exe $(SRC)

# Test target
test: $(TEST_EXEC)
	@echo "Exécution des tests unitaires..."
	./$(TEST_EXEC)

# Build test executable
$(TEST_EXEC): $(TEST_SRC) $(SRC_SQLITE) Src/database.c
	@$(MKDIR)
	$(CC) $(CFLAGS) -o $@ $^

#	Cible pour exécuter les tests d'intégration.
test-integration: $(TEST_INTEGRATION_EXEC)
	@echo "Exécution du test d'intégration..."
	./$(TEST_INTEGRATION_EXEC)

$(TEST_INTEGRATION_EXEC): $(TEST_INTEGRATION_SRC) $(SRC_SQLITE) $(SRC_SRC)
	@$(MKDIR)
	$(CC) $(CFLAGS) -o $@ $^

#	Cible pour exécuter les tests valgrind.
ifeq ($(OS),Windows_NT)
valgrind-test:
	@echo "Valgrind n'est pas disponible sur Windows. Utilisez WSL ou CI."
valgrind-integration:
	@echo "Valgrind n'est pas disponible sur Windows. Utilisez WSL ou CI."
else
valgrind-test: $(TEST_EXEC)
	valgrind --leak-check=full --error-exitcode=1 ./$(TEST_EXEC)

valgrind-integration: $(TEST_INTEGRATION_EXEC)
	valgrind --leak-check=full --error-exitcode=1 ./$(TEST_INTEGRATION_EXEC)
endif

#Code coverage tools track which lines of code are executed during tests. This helps you:
#Spot dead or unused code
#Identify untested branches or conditions
#Improve test completeness
COVERAGE_FLAGS = -fprofile-arcs -ftest-coverage -g -O0

coverage: CFLAGS += $(COVERAGE_FLAGS)
coverage: LDFLAGS += -lgcov
coverage: clean $(TEST_EXEC)
	@echo "Exécution des tests avec couverture..."
	./$(TEST_EXEC)
	@echo "Génération du rapport de couverture..."
	gcovr -r . --html --html-details -o build/coverage.html




