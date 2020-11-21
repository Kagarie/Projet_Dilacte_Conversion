#ifndef ARRAY_H_
#define ARRAY_H_

#include <stddef.h>
#include <stdlib.h>

typedef struct _Array Array;

extern Array *array_create(const unsigned int index, const unsigned int nombre, char *mot);

extern void array_destroy(Array *array);

//On retourne l'index
extern unsigned int array_get_index(const Array *array);

//On retourne le nombre de la sous-structure
extern unsigned int array_get_nombre(const Array *array);

//On retourne le mot de la sous-structure
extern char *array_get_mot(const Array *array);

extern void *array_affiche(const Array *array);

#endif //ARRAY_H_