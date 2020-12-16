/**
 * Main structure
 * @struct ChiffreEnLettre
 */
#include "./numberToLetter.h"

//This is our base structure
struct _NumberToLetter {
    int number;
    char *word;
    NumberToLetter *next;
};