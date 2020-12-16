#ifndef MAIN_H_
#define MAIN_H_

#include <yaml.h>
#include <array.h>
#include <utils.h>
#include <numberToLetter.h>

/**
 * Show all yaml
 */
extern void dialect_show();

/**
 * Allows you to read a yaml type file and add
 * it to a stack that contains numberToLetter structures
 * @param array
 * @param dialect
 */
extern void yaml(Array *array, char *dialect);

/**
 * Search the reference yaml sheet
 * @param research
 * @return
 */
extern char *conversion_reference(char *research);

/**
 * Converts a number to its equivalent in a letter
 * @param dialect
 * @param number
 * @return
 */
extern char *conversion(char *dialect, char *number);

/**
 * Allows you to convert a date into a number in its equivalent letter
 * @param date
 * @return
 */
extern char *conversion_date(char *date);

/**
 * Allows converting a number into a Roman numeral
 * @param number
 * @return
 */
extern char *conversion_romain(char *number);

/**
 * Main of the program. It takes two arguments at launch a dilact and a number
 * @param argc
 * @param argv
 * @return
 */
extern int main(int argc, char *argv[]);

#endif //ARRAY_H_