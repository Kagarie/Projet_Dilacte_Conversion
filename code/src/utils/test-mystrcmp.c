#include <stdlib.h>
#include <stdio.h>

#ifdef NDEBUG
#undef NDEBUG
#endif

#include <assert.h>

#include "./utils.h"

int main(void) {
    char *mot1 = "moi";
    char *mot2 = " lui";
    char *mot3="moi";
    printf("test bool : %d \n",mystrcmp(mot1,mot2));
    printf("test bool : %d \n",mystrcmp(mot1,mot3));
    return EXIT_SUCCESS;
}
