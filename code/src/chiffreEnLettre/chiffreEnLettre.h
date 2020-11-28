#ifndef CHIFFREENLETTRE_H_
#define CHIFFREENLETTRE_H_


#include <stddef.h>
#include <stdlib.h>

//structure present de le .inc
typedef struct _ChiffreEnLettre ChiffreEnLettre;

/* --------------FONCTION------------- */

extern void *(*chiffreEnLettre_malloc)(size_t size);

extern void *(*chiffreEnLettre_realloc)(void *ptr, size_t size);

extern void (*chiffreEnLettre_free)(void *ptr);

//On attribut un nombre à n'autre structure
extern void chiffreEnLettre_set_nombre(ChiffreEnLettre *chiffreEnLettre, int nombre);

//On retourne le nombre de la structure
extern int chiffreEnLettre_get_nombre(const ChiffreEnLettre *chiffreEnLettre);

//On attribut un mot a notre structure
extern void chiffreEnLettre_set_mot(ChiffreEnLettre *chiffreEnLettre, char *monMot);

//On return le mot de la structure
extern char *chiffreEnLettre_get_mot(const ChiffreEnLettre *chiffreEnLettre);

//On attribut un élément un pointeur sur la structure suivant
extern void chiffreEnLettre_set_suivant(ChiffreEnLettre *ch, ChiffreEnLettre *suivant);

//On return le pointeur de la structure suivante
extern ChiffreEnLettre *chiffreEnLettre_get_suivant(const ChiffreEnLettre *chiffreEnLettre);

//Fonction pour créer notre sturcture
extern ChiffreEnLettre *chiffreEnLettre_create_full(const int nombre, char *mot);

//On détruit la structure et on libère la mémoire
extern void chiffreEnLettre_destroy(ChiffreEnLettre *chiffreEnLettre);

extern int chiffreEnLettre_get_taille();


#endif // CHIFFREENLETTRE_H_