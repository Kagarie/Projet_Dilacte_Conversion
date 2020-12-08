/**
 * @file chiffreEnLettre
 */
#ifndef CHIFFREENLETTRE_H_
#define CHIFFREENLETTRE_H_


#include <stddef.h>
#include <stdlib.h>

/**
 * Structure
 */
typedef struct _ChiffreEnLettre ChiffreEnLettre;

/**
 * Malloc de la structure
 * @param size
 * @return
 */
extern void *(*chiffreEnLettre_malloc)(size_t size);

/**
 * Realloc de la structure
 * @param ptr
 * @param size
 * @return
 */
extern void *(*chiffreEnLettre_realloc)(void *ptr, size_t size);

/**
 * free de la structure
 * @param ptr
 */
extern void (*chiffreEnLettre_free)(void *ptr);

/**
 * Permet de changer le nombre
 * @param chiffreEnLettre
 * @param nombre
 */
extern void chiffreEnLettre_set_nombre(ChiffreEnLettre *chiffreEnLettre, int nombre);

/**
 * Retourne le nombre de la structure
 * @param chiffreEnLettre
 * @return
 */
extern int chiffreEnLettre_get_nombre(const ChiffreEnLettre *chiffreEnLettre);

/**
 *Permet de changer le mot de la structure
 * @param chiffreEnLettre
 * @param monMot
 */
extern void chiffreEnLettre_set_mot(ChiffreEnLettre *chiffreEnLettre, char *monMot);

/**
 * Rtourne le mot de la structure
 * @param chiffreEnLettre
 * @return
 */
extern char *chiffreEnLettre_get_mot(const ChiffreEnLettre *chiffreEnLettre);

/**
 * Retourne l'élément sur lequel il pointe
 * @param chiffreEnLettre
 * @param chiffreEnLettreSuivant
 */
extern void chiffreEnLettre_set_suivant(ChiffreEnLettre *ch, ChiffreEnLettre *suivant);

/**
 * Permet de changer l'élément sur lequel il pointe
 * @param chiffreEnLettre
 * @return
 */
extern ChiffreEnLettre *chiffreEnLettre_get_suivant(const ChiffreEnLettre *chiffreEnLettre);

/**
 * Creation de la structure
 * @param nombre
 * @param mot
 * @return
 */
extern ChiffreEnLettre *chiffreEnLettre_create_full(const int nombre, char *mot);

/**
 * Destruction de la structure
 * @param chiffreEnLettre
 */
extern void chiffreEnLettre_destroy(ChiffreEnLettre *chiffreEnLettre);

/**
 * Retourne la taille que prends la structure
 * @return
 */
extern int chiffreEnLettre_get_taille();


#endif // CHIFFREENLETTRE_H_