#include "./array.h"
#include "./array.inc"

#include <stdio.h>

Array *array_initialisation() {
    Array *array = malloc(sizeof(Array));
    NumberToLetter *numberToLetter = malloc(sizeof(numberToLetter_get_size()));
    if (array == NULL || numberToLetter == NULL) {
        free(numberToLetter);
        free(array);
        exit(EXIT_FAILURE);
    }
    numberToLetter_set_number(numberToLetter, -1);
    numberToLetter_set_word(numberToLetter, NULL);
    numberToLetter_set_next(numberToLetter, NULL);
    array->first = numberToLetter;
    return array;
}

void array_destroy(Array *array) {
    if (array == NULL) {
        exit(EXIT_FAILURE);
    }
    NumberToLetter *nb = array->first;

    while (nb != NULL) {
        numberToLetter_destroy(nb);
        nb = numberToLetter_get_next(nb);
    }
    free(array);
}

int array_get_number(Array *array) {
    return numberToLetter_get_number(array->first);
}

char *array_get_word(Array *array) {
    return numberToLetter_get_word(array->first);
}

NumberToLetter *array_get_first(Array *array) {
    return numberToLetter_get_next(array->first);
}

void *array_insertion(Array *array, int number, char *word) {
    NumberToLetter *new = malloc(sizeof(numberToLetter_get_size()));
    if (array == NULL || new == NULL) {
        free(new);
        free(array);
        exit(EXIT_FAILURE);
    }
    /* Insertion of the first element of the list */
    numberToLetter_set_number(new, number);
    numberToLetter_set_word(new, word);
    numberToLetter_set_next(new, array->first);
    array->first = new;
}

void *array_show(Array *array) {
    if (array == NULL) {
        exit(EXIT_FAILURE);
    }
    NumberToLetter *nb = array->first;

    while (nb != NULL) {
        printf("number : %d word :%s\n", numberToLetter_get_number(nb), numberToLetter_get_word(nb));
        nb = numberToLetter_get_next(nb);
    }
}