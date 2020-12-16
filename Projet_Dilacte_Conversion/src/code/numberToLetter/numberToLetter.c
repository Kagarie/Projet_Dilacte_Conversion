
#include "./numberToLetter.inc"
#include "./numberToLetter.h"


void *(*numberToLetter_malloc)(size_t size) =malloc;

void *(*numberToLetter_realloc)(void *ptr, size_t size) =realloc;

void (*numberToLetter_free)(void *ptr) =free;

void numberToLetter_set_number(NumberToLetter *numberToLetter, int number) {
    numberToLetter->number = number;
}

int numberToLetter_get_number(const NumberToLetter *numberToLetter) {
    return numberToLetter->number;
}

void numberToLetter_set_word(NumberToLetter *numberToLetter, char *word) {
    numberToLetter->word = word;
}

char *numberToLetter_get_word(const NumberToLetter *numberToLetter) {
    return numberToLetter->word;
}


void numberToLetter_set_next(NumberToLetter *numberToLetter, NumberToLetter *numberToLetterNext) {
    numberToLetter->next = numberToLetterNext;

}

NumberToLetter *numberToLetter_get_next(const NumberToLetter *numberToLetter) {
    return numberToLetter->next;
}

static NumberToLetter *_fill(NumberToLetter *numberToLetter, const unsigned number, char *word) {
    numberToLetter->number = number;
    numberToLetter->word = word;
    return numberToLetter;
}

NumberToLetter *numberToLetter_create_full(const int number, char *word) {
    NumberToLetter *numberToLetter= numberToLetter_malloc(sizeof(numberToLetter));
    if (numberToLetter) {
        return _fill(numberToLetter, number, word);
    } else {
        return NULL;
    }
}

void numberToLetter_destroy(NumberToLetter *numberToLetter) {
    numberToLetter_free(numberToLetter);
}

int numberToLetter_get_size() {
    return sizeof(NumberToLetter);
}