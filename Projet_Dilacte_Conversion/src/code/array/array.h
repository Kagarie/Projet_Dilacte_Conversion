/**
 * @file Array
 * Fonction Array
 *
 */
#ifndef ARRAY_H_
#define ARRAY_H_

#include <stddef.h>
#include <stdlib.h>
#include <numberToLetter.h>

/**
 * Structure
 */
typedef struct _Array Array;

/**
 * stack's initialisation
 * @return
 */
extern Array *array_initialisation();

/**
 * stack's deletion with the inside
 * @param array
 */
extern void array_destroy(Array *array);

/**
 * Gives the number of the current NumberToLetter element 
 * @param array
 * @return
 */
extern int array_get_number(Array *array);

/**
 * Gives the word of the current NumberToLetter element 
 * @param array
 * @return
 */
extern char *array_get_word(Array *array);

/**
 * Gives the current NumberToLetter element
 * @param array
 * @return
 */
extern NumberToLetter *array_get_first(Array *array);

/**
 * Generate an element of the structure NumberToLetter and add it to the stack
 * @param array
 * @param number
 * @param word
 * @return
 */
extern void *array_insertion(Array *array, int number, char *word);


/**
 * Show the stack
 * @param array
 * @return
 */
extern void *array_show(Array *array);

#endif //ARRAY_H_
