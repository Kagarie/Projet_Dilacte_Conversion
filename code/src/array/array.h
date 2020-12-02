#ifndef ARRAY_H_
#define ARRAY_H_

#include <stddef.h>
#include <stdlib.h>
#include <chiffreEnLettre.h>

typedef struct _Array Array;

extern Array *array_initialisation();

extern void array_destroy(Array *array);

extern int array_get_nombre(Array *array);

extern char *array_get_mot(Array *array);

extern ChiffreEnLettre *array_get_premier(Array *array);

extern void *array_insertion(Array *array, int nombre, char *mot);

extern void *array_affiche(Array *array);

#endif //ARRAY_H_
