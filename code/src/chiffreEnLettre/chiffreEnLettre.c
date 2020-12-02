/**
 * @file chiffreEnLettre
 */

#include "./chiffreEnLettre.inc"
#include "./chiffreEnLettre.h"

/**
 * Malloc de la structure
 * @param size
 * @return
 */
void *(*chiffreEnLettre_malloc)(size_t size) =malloc;

/**
 * Realloc de la structure
 * @param ptr
 * @param size
 * @return
 */
void *(*chiffreEnLettre_realloc)(void *ptr, size_t size) =realloc;

/**
 * free de la structure
 * @param ptr
 */
void (*chiffreEnLettre_free)(void *ptr) =free;

/**
 * Permet de changer le nombre
 * @param chiffreEnLettre
 * @param nombre
 */
void chiffreEnLettre_set_nombre(ChiffreEnLettre *chiffreEnLettre, int nombre) {
    chiffreEnLettre->nombre = nombre;
}

/**
 * Retourne le nombre de la structure
 * @param chiffreEnLettre
 * @return
 */
int chiffreEnLettre_get_nombre(const ChiffreEnLettre *chiffreEnLettre) {
    return chiffreEnLettre->nombre;
}

/**
 *Permet de changer le mot de la structure
 * @param chiffreEnLettre
 * @param monMot
 */
void chiffreEnLettre_set_mot(ChiffreEnLettre *chiffreEnLettre, char *monMot) {
    chiffreEnLettre->mot = monMot;
}

/**
 * Rtourne le mot de la structure
 * @param chiffreEnLettre
 * @return
 */
char *chiffreEnLettre_get_mot(const ChiffreEnLettre *chiffreEnLettre) {
    return chiffreEnLettre->mot;
}

/**
 * Retourne l'élément sur lequel il pointe
 * @param chiffreEnLettre
 * @param chiffreEnLettreSuivant
 */
void chiffreEnLettre_set_suivant(ChiffreEnLettre *chiffreEnLettre, ChiffreEnLettre *chiffreEnLettreSuivant) {
    chiffreEnLettre->suivant = chiffreEnLettreSuivant;

}

/**
 * Permet de changer l'élément sur lequel il pointe
 * @param chiffreEnLettre
 * @return
 */
ChiffreEnLettre *chiffreEnLettre_get_suivant(const ChiffreEnLettre *chiffreEnLettre) {
    return chiffreEnLettre->suivant;
}


/**
 *
 * @param chiffreEnLettre
 * @param nombre
 * @param mot
 * @return
 */
//On ajoute les valeurs à notre structure
static ChiffreEnLettre *_fill(ChiffreEnLettre *chiffreEnLettre, const unsigned nombre, char *mot) {
    chiffreEnLettre->nombre = nombre;
    chiffreEnLettre->mot = mot;
    return chiffreEnLettre;
}

/**
 * Creation de la structure
 * @param nombre
 * @param mot
 * @return
 */
ChiffreEnLettre *chiffreEnLettre_create_full(const int nombre, char *mot) {
    ChiffreEnLettre *chiffreEnLettre = chiffreEnLettre_malloc(sizeof(chiffreEnLettre));
    if (chiffreEnLettre) {
        return _fill(chiffreEnLettre, nombre, mot);
    } else {
        return NULL;
    }
}

/**
 * Destruction de la structure
 * @param chiffreEnLettre
 */
void chiffreEnLettre_destroy(ChiffreEnLettre *chiffreEnLettre) {
    chiffreEnLettre_free(chiffreEnLettre);
}

/**
 * Retourne la taille que prends la structure
 * @return
 */
int chiffreEnLettre_get_taille() {
    return sizeof(ChiffreEnLettre);
}

