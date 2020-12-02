/**
 * @file utils
 * Feuille qui regroupe plusieurs fonctions utils
 */
#include "./utils.h"

/**
 * Permet de concaténer deux chaines de caractéres entre elle
 * @param destination
 * @param source
 * @return
 */
char *my_strcat(char *destination, const char *source) {
    //calcul de la longueur minimum
    char *ptr = destination + strlen(destination);

    // on ajoute les caractères
    while (*source != '\0')
        *ptr++ = *source++;

    // ajout du caractère de fin de chaines
    *ptr = '\0';

    // on retourne la resultat des chaines
    return destination;
}

/**
 * Permet de verifier que deux chaines soient exactement identique
 * @param s1
 * @param s2
 * @return
 */
int mystrcmp(const char *s1, const char *s2) {
    int i = 0;
    do {
        if (s1[i] != s2[i])
            return 1;
        i++;
    } while (s1[i - 1] != 0);
    return 0;
}



