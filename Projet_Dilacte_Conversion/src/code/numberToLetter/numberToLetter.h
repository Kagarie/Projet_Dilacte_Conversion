/**
 * @file numberToLetter
 */
#ifndef NUMBERTOLETTER_H_
#define NUMBERTOLETTER_H_


#include <stddef.h>
#include <stdlib.h>

/**
 * Structure
 */
typedef struct _NumberToLetter NumberToLetter;

/**
 * Malloc of the structure
 * @param size
 * @return
 */
extern void *(*numberToLetter_malloc)(size_t size);

/**
 * Realloc of the structure
 * @param ptr
 * @param size
 * @return
 */
extern void *(*numberToLetter_realloc)(void *ptr, size_t size);

/**
 * free of the structure
 * @param ptr
 */
extern void (*numberToLetter_free)(void *ptr);

/**
 * Change the number
 * @param numberToLetter
 * @param number
 */
extern void numberToLetter_set_number(NumberToLetter *numberToLetter, int number);

/**
 * Return the number
 * @param chiffreEnLettre
 * @return
 */
extern int numberToLetter_get_number(const NumberToLetter *numberToLetter);

/**
 * Change the word
 * @param numberToLetter
 * @param world
 */
extern void numberToLetter_set_word(NumberToLetter *numberToLetter, char *word);

/**
 * Return the word
 * @param numberToLetter
 * @return
 */
extern char *numberToLetter_get_word(const NumberToLetter *numberToLetter);

/**
 *
 * @param ch
 * @param next
 */
extern void numberToLetter_set_next(NumberToLetter *ch, NumberToLetter *next);

/**
 *
 * @param numberToLetter
 * @return
 */
extern NumberToLetter *numberToLetter_get_next(const NumberToLetter *numberToLetter);

/**
 * Creation of the structure
 * @param number
 * @param world
 * @return
 */
extern NumberToLetter *numberToLetter_create_full(const int number, char *word);

/**
 * Destroy of the structure
 * @param numberToLetter
 */
extern void numberToLetter_destroy(NumberToLetter *numberToLetter);

/**
 * Return size of the structure
 * @return
 */
extern int numberToLetter_get_size();


#endif // NUMBERTOLETTER_H_