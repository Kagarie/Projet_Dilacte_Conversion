#include <stdio.h>
#include "./utils.h"

// ma propre function strcat
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


int mystrcmp(const char *s1, const char *s2) {
    int i = 0;
    do {
        if (s1[i] != s2[i])
            return 1;
        i++;
    } while (s1[i - 1] != 0);
    return 0;
}

char *tronqueChaine(char *destination, const char *source, int lenght) {
    char *ptr = destination;
    for (int (i) = 0; (i) < lenght; i++)
        *ptr++ = *source++;

    printf("%s\n",ptr);
    *ptr = '\0';
    return destination;
}

