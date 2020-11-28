#include "./array.h"
#include "./array.inc"
#include "./chiffreEnLettre.h"

#include <stdio.h>


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
    chiffreEnLettre_set_suivant(array->premier, nouveau);
}

void *array_affiche(const Array *array) {
    if (array == NULL) {
        exit(EXIT_FAILURE);
    }
    ChiffreEnLettre *ch = array->premier;
    while (chiffreEnLettre_get_suivant(ch)!= NULL) {
        printf("nombre : %d et mot : %s\n", chiffreEnLettre_get_nombre(array->premier),
               chiffreEnLettre_get_mot(array->premier));
        ch = chiffreEnLettre_get_suivant(array->premier);
    }
    printf("NULL\n");
}