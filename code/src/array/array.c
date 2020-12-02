/**
 * @file Array
 * Fonction Array
 *
 */

#include "./array.h"
#include "./array.inc"
#include "./chiffreEnLettre.h"

#include <stdio.h>

/**
 * Initialisation de la pile
 * @return
 */
Array *array_initialisation() {
    Array *array = malloc(sizeof(Array));
    ChiffreEnLettre *chiffreEnLettre = malloc(sizeof(chiffreEnLettre_get_taille()));
    if (array == NULL || chiffreEnLettre == NULL) {
        free(chiffreEnLettre);
        free(array);
        exit(EXIT_FAILURE);
    }
    chiffreEnLettre_set_nombre(chiffreEnLettre, -1);
    chiffreEnLettre_set_mot(chiffreEnLettre, NULL);
    chiffreEnLettre_set_suivant(chiffreEnLettre, NULL);
    array->premier = chiffreEnLettre;
    return array;
}


/**
 * Destruction de la pile et de son contenu
 * @param array
 */
void array_destroy(Array *array) {
    if (array == NULL) {
        exit(EXIT_FAILURE);
    }
    ChiffreEnLettre *ch = array->premier;

    while (ch != NULL) {
        chiffreEnLettre_destroy(ch);
        ch = chiffreEnLettre_get_suivant(ch);
    }
    free(array);
}

/**
 * Return le nombre de la strucuture ChiffreEnLettre
 * @param array
 * @return
 */
int array_get_nombre(Array *array) {
    return chiffreEnLettre_get_nombre(array->premier);
}

/**
 * Return le mot de la structure ChiffreEnLettre
 * @param array
 * @return
 */
char *array_get_mot(Array *array) {
    return chiffreEnLettre_get_mot(array->premier);
}

/**
 * Return l'élément de la pile sur lequel on est
 * @param array
 * @return
 */
ChiffreEnLettre *array_get_premier(Array *array) {
    return chiffreEnLettre_get_suivant(array->premier);
}

/**
 * Génére une structure ChiffreEnLettre et l'ajoute à la pile
 * @param array
 * @param nombre
 * @param mot
 * @return
 */
void *array_insertion(Array *array, int nombre, char *mot) {
    ChiffreEnLettre *nouveau = malloc(sizeof(chiffreEnLettre_get_taille()));
    if (array == NULL || nouveau == NULL) {
        free(nouveau);
        free(array);
        exit(EXIT_FAILURE);
    }
    /* Insertion de l'élément au début de la liste */
    chiffreEnLettre_set_nombre(nouveau, nombre);
    chiffreEnLettre_set_mot(nouveau, mot);
    chiffreEnLettre_set_suivant(nouveau, array->premier);
    array->premier = nouveau;
}

/**
 * Permet d'afficher la pile
 * @param array
 * @return
 */
void *array_affiche(Array *array) {
    if (array == NULL) {
        exit(EXIT_FAILURE);
    }
    ChiffreEnLettre *ch = array->premier;

    while (ch != NULL) {
        printf("nombre : %d mot :%s\n", chiffreEnLettre_get_nombre(ch), chiffreEnLettre_get_mot(ch));
        ch = chiffreEnLettre_get_suivant(ch);
    }
}