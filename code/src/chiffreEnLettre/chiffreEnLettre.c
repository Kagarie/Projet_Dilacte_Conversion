#include "./chiffreEnLettre.inc"
#include "./chiffreEnLettre.h"

void *(*chiffreEnLettre_malloc)(size_t size) =malloc;

void *(*chiffreEnLettre_realloc)(void *ptr, size_t size) =realloc;

void (*chiffreEnLettre_free)(void *ptr) =free;


void chiffreEnLettre_set_nombre(ChiffreEnLettre *chiffreEnLettre, int nombre) {
    chiffreEnLettre->nombre = nombre;
}

int chiffreEnLettre_get_nombre(const ChiffreEnLettre *chiffreEnLettre) {
    return chiffreEnLettre->nombre;
}

void chiffreEnLettre_set_mot(ChiffreEnLettre *chiffreEnLettre, char *monMot) {
    chiffreEnLettre->mot = monMot;
}

char *chiffreEnLettre_get_mot(const ChiffreEnLettre *chiffreEnLettre) {
    return chiffreEnLettre->mot;
}

//On ajoute les valeurs à notre structure
static ChiffreEnLettre *_fill(ChiffreEnLettre *chiffreEnLettre, const unsigned nombre, char *mot) {
    chiffreEnLettre->nombre = nombre;
    chiffreEnLettre->mot = mot;
    return chiffreEnLettre;
}

ChiffreEnLettre *chiffreEnLettre_create_full(const int nombre, char *mot) {
    ChiffreEnLettre *chiffreEnLettre = chiffreEnLettre_malloc(sizeof(chiffreEnLettre));
    if (chiffreEnLettre) {
        return _fill(chiffreEnLettre, nombre, mot);
    } else {
        return NULL;
    }
}

void chiffreEnLettre_destroy(ChiffreEnLettre *chiffreEnLettre) {
    chiffreEnLettre_free(chiffreEnLettre);
}

int chiffreEnLettre_get_taille() {
    return sizeof(ChiffreEnLettre);
}

void chiffreEnLettre_set_suivant(ChiffreEnLettre *chiffreEnLettre, ChiffreEnLettre *chiffreEnLettreSuivant) {
    chiffreEnLettre->suivant = chiffreEnLettreSuivant;

}

ChiffreEnLettre *chiffreEnLettre_get_suivant(const ChiffreEnLettre *chiffreEnLettre) {
    return chiffreEnLettre->suivant;
}
