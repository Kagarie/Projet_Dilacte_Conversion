#include "./chiffreEnLettre.inc"
#include "./chiffreEnLettre.h"

void *(*chiffreEnLettre_malloc)(size_t size) =malloc;

void *(*chiffreEnLettre_realloc)(void *ptr, size_t size) =realloc;

void (*chiffreEnLettre_free)(void *ptr) =free;

unsigned int chiffreEnLettre_get_nombre(const ChiffreEnLettre *chiffreEnLettre) {
    return chiffreEnLettre->nombre;
}

char chiffreEnLettre_get_mot(const ChiffreEnLettre *chiffreEnLettre) {
    return chiffreEnLettre->nombreEnLettre;
}

static struct ChiffreEnLettre *_fill(ChiffreEnLettre *chiffreEnLettre, const unsigned nombre, const char mot) {
    chiffreEnLettre->nombre = nombre;
    chiffreEnLettre->nombreEnLettre = mot;
    return chiffreEnLettre;
}

static ChiffreEnLettre *_create(const unsigned int nombre, const char mot) {
    ChiffreEnLettre *chiffreEnLettre = chiffreEnLettre_malloc(sizeof *chiffreEnLettre);
    if (chiffreEnLettre) {
        return _fill(chiffreEnLettre, nombre, mot);
    } else {
        return NULL;
    }
}

void chiffreEnLettre_destroy(ChiffreEnLettre *chiffreEnLettre){
    chiffreEnLettre_free(chiffreEnLettre);
}