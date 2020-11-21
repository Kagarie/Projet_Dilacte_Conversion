#include "./array.h"
#include "./array.inc"


Array *array_create(const unsigned int index, const unsigned int nombre, char *mot) {
    Array *array = malloc(sizeof(array));
    if (array) {
        array->index = index;
        array->chiffreEnLettre = chiffreEnLettre_create_full(nombre, mot);
        if (!array->chiffreEnLettre) {
            free(array);
            array = NULL;
        }
    }
    return array;
}

void array_destroy(Array *array) {
    chiffreEnLettre_destroy(array->chiffreEnLettre);
    free(array);
}

unsigned int array_get_index(const Array *array) {
    return array->index;
}

unsigned int array_get_nombre(const Array *array) {
    return chiffreEnLettre_get_nombre(array->chiffreEnLettre);
}

char *array_get_mot(const Array *array) {
    return chiffreEnLettre_get_mot(array->chiffreEnLettre);
}