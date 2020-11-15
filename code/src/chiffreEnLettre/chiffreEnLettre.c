#include "./chiffreEnLettre.inc"
#include "./chiffreEnLettre.h"

void *(*chiffreEnLettre_malloc)(size_t size) =malloc;

void *(*chiffreEnLettre_realloc)(void *ptr, size_t size) =realloc;

void (*chiffreEnLettre_free)(void *ptr) =free;

unsigned int chiffreEnLettre_get_nombre(const ChiffreEnLettre *chiffreEnLettre) {
    return chiffreEnLettre->nombre;
}

char *chiffreEnLettre_get_mot(const ChiffreEnLettre *chiffreEnLettre) {
    return chiffreEnLettre->mot;
}

//On ajoute les valeurs à notre structure
static ChiffreEnLettre *_fill(ChiffreEnLettre *chiffreEnLettre, const unsigned nombre,char* mot) {
    chiffreEnLettre->nombre = nombre;
    chiffreEnLettre->mot = mot;
    return chiffreEnLettre;
}

 ChiffreEnLettre *chiffreEnLettre_create_full(const int nombre,char *mot) {
    ChiffreEnLettre *chiffreEnLettre = chiffreEnLettre_malloc(sizeof((chiffreEnLettre)));
    if(chiffreEnLettre){
        return _fill(chiffreEnLettre,nombre,mot);
    }else{
        return NULL;
    }
}

void chiffreEnLettre_destroy(ChiffreEnLettre *chiffreEnLettre) {
    chiffreEnLettre_free(chiffreEnLettre);
}