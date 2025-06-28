/**
 * @file utils.c
 * @brief Fonctions utilitaires pour la gestion des entrées utilisateur.
 * 
 * @author Oussama Amara
 * @date 2024-06-28
 * @version 1.0
 */
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include "utils.h"

/**
 * @brief Lit une chaîne de caractères depuis l'entrée standard.
 *
 * Cette fonction lit une ligne de texte, supprime le caractère '\n' s'il est présent,
 * et vide le tampon si l'entrée dépasse la taille du buffer.
 *
 * @param buffer Le tableau où stocker la chaîne lue.
 * @param taille La taille maximale du buffer (incluant le '\0').
 * @return 0 si la lecture est réussie, -1 en cas d'erreur.
 */
int lire_chaine(char *buffer, size_t taille) {
    if (!fgets(buffer, taille, stdin)) return -1;

    // Vérifie si la ligne a été complètement lue
    if (strchr(buffer, '\n') == NULL) {
        int c;
        while ((c = getchar()) != '\n' && c != EOF); // Vide le reste du tampon
    }

    // Supprime le '\n' s'il est présent
    buffer[strcspn(buffer, "\n")] = '\0';
    return 0;
}

/**
 * @brief Reads an integer from standard input.
 *
 * This function reads a line from stdin, removes the trailing newline character,
 * and checks if the input consists only of digit characters. If the input is valid,
 * it converts the string to an integer and returns it. If the input is invalid or
 * reading fails, it returns -1.
 *
 * @return The integer value read from input, or -1 if input is invalid or reading fails.
 */
int lire_entier() {
    char buffer[32];
    if (!fgets(buffer, sizeof(buffer), stdin)) return -1;

    // Vérifie si la ligne a été complètement lue
    if (strchr(buffer, '\n') == NULL) {
        int c;
        while ((c = getchar()) != '\n' && c != EOF); // Vide le reste de la ligne
        return -1; // Entrée trop longue
    }

    buffer[strcspn(buffer, "\n")] = '\0';

    for (size_t i = 0; buffer[i]; i++) {
        if (!isdigit(buffer[i])) return -1;
    }

    return atoi(buffer);
}

/**
 * @brief Reads a floating-point number from standard input.
 *
 * This function prompts the user to enter a floating-point number as a string,
 * validates the input to ensure it contains only digits and at most one decimal point,
 * and then converts it to a float. If the input is invalid or reading fails,
 * the function returns -1.0f.
 *
 * @return The floating-point value entered by the user, or -1.0f if input is invalid.
 */

float lire_flottant() {
    char buffer[32];
    if (!fgets(buffer, sizeof(buffer), stdin)) return -1.0f;

    if (strchr(buffer, '\n') == NULL) {
        int c;
        while ((c = getchar()) != '\n' && c != EOF);
        return -1.0f;
    }

    buffer[strcspn(buffer, "\n")] = '\0';

    int point_count = 0;
    for (size_t i = 0; buffer[i]; i++) {
        if (buffer[i] == '.') {
            point_count++;
            if (point_count > 1) return -1.0f;
        } else if (!isdigit(buffer[i])) {
            return -1.0f;
        }
    }

    return strtof(buffer, NULL);
}
