#include <stdlib.h>
#include <stdio.h>

#ifdef NDEBUG
#undef NDEBUG
#endif

#include <assert.h>

#include "./utils.h"

int main(void) {
    char *mot1 = "Bonjour, comment allez vous ? ";
    char *mot2=NULL;
    tronqueChaine(mot2,mot1,5);
    printf("%s\n",mot2);
    return EXIT_SUCCESS;
}
