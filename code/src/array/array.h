#ifndef ARRAY_H_
#define ARRAY_H_

#include <stddef.h>
#include <stdlib.h>
#include <chiffreEnLettre.h>

typedef struct _Array Array;

extern Array *array_initialisation();

//extern void array_destroy(Array *array);


//On ajoute un élément
extern void *array_insertion(Array *array, int nombre, char *mot);

//On affiche l'array
extern void *array_affiche(const Array *array);

#endif //ARRAY_H_
