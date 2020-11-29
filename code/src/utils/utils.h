#ifndef UTILS_H_
#define UTILS_H_


#include <string.h>

//Ceci est un fichier qui regroupe des fonctions qui nous servent dans le progrmme
extern char *my_strcat(char *destination, const char *source);

//fonction pour vérifier que deux chaines soient exactement identique
extern int mystrcmp(const char *s1, const char *s2);

//fonction pour tronquer une chaine
extern char *tronqueChaine(char *destination, const char *source, int lenght);

#endif //UTILS_H_