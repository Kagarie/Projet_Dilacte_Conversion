/**
 * @file utils
 * useful functions
 */

#ifndef UTILS_H_
#define UTILS_H_

#include <string.h>

/**
 * Concatenation of two strings
 * @param destination
 * @param source
 * @return
 */
extern char *my_strcat(char *destination, const char *source);


/**
 * Check that two strings are identical
 * @param s1
 * @param s2
 * @return
 */
extern int mystrcmp(const char *s1, const char *s2);

#endif //UTILS_H_