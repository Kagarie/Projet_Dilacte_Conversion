#include <stddef.h>
#include <stdlib.h>
//structure present de le .inc
typedef struct _ChiffreEnLettre ChiffreEnLettre;

/* --------------FONCTION------------- */

extern void *(*chiffreEnLettre_malloc)(size_t size);

extern void *(*chiffreEnLettre_realloc)(void *ptr, size_t size);

extern void (*chiffreEnLettre_free)(void *ptr);

//On retourne le nombre de la structure
extern unsigned int chiffreEnLettre_get_nombre(const ChiffreEnLettre *chiffreEnLettre);

//On return le mot de la structure
extern char *chiffreEnLettre_get_mot(const ChiffreEnLettre *chiffreEnLettre);

//Fonction pour créer notre sturcture
extern ChiffreEnLettre *chiffreEnLettre_create_full(const int nombre, char* mot);

//On détruit la mémoire et on libère la mémoire
extern void chiffreEnLettre_destroy(ChiffreEnLettre *chiffreEnLettre);