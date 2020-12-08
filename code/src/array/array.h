/**
 * @file Array
 * Fonction Array
 *
 */
#ifndef ARRAY_H_
#define ARRAY_H_

#include <stddef.h>
#include <stdlib.h>
#include <chiffreEnLettre.h>

/**
 * Structure
 */
typedef struct _Array Array;

/**
 * Initialisation de la pile
 * @return
 */
extern Array *array_initialisation();

/**
 * Destruction de la pile et de son contenu
 * @param array
 */
extern void array_destroy(Array *array);

/**
 * Return le nombre de la strucuture ChiffreEnLettre
 * @param array
 * @return
 */
extern int array_get_nombre(Array *array);

/**
 * Return le mot de la structure ChiffreEnLettre
 * @param array
 * @return
 */
extern char *array_get_mot(Array *array);

/**
 * Return l'élément de la pile sur lequel on est
 * @param array
 * @return
 */
extern ChiffreEnLettre *array_get_premier(Array *array);

/**
 * Génére une structure ChiffreEnLettre et l'ajoute à la pile
 * @param array
 * @param nombre
 * @param mot
 * @return
 */
extern void *array_insertion(Array *array, int nombre, char *mot);


/**
 * Permet d'afficher la pile
 * @param array
 * @return
 */
extern void *array_affiche(Array *array);

#endif //ARRAY_H_
