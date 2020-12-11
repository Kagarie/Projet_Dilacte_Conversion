#include <stdlib.h>
#include <stdio.h>

#ifdef NDEBUG
#undef NDEBUG
#endif

#include <assert.h>

#include "./utils.h"

int main(void) {
    char *mot1 = "moi";
    char *mot2 = "lui";
    my_strcat(mot1 ,mot2);
    //printf("mot final %s :",mot1);
    return EXIT_SUCCESS;
}