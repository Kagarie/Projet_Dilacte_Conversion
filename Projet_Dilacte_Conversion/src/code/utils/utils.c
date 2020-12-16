#include "./utils.h"


char *my_strcat(char *destination, const char *source){
    char *ptr = destination + strlen(destination);
    while (*source != '\0')
        *ptr++ = *source++;

    *ptr = '\0';
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



