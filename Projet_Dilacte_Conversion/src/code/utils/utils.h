/**
 * @file utils
 * Feuille qui regroupe plusieurs fonctions utils
 */

#ifndef UTILS_H_
#define UTILS_H_

#include <string.h>

/**
 * Permet de concaténer deux chaines de caractéres entre elle
 * @param destination
 * @param source
 * @return
 */
extern char *my_strcat(char *destination, const char *source);


/**
 * Permet de verifier que deux chaines soient exactement identique
 * @param s1
 * @param s2
 * @return
 */
extern int mystrcmp(const char *s1, const char *s2);

#endif //UTILS_H_