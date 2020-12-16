#include <stdlib.h>
#include <stdio.h>

#ifdef NDEBUG
#undef NDEBUG
#endif

#include <assert.h>

#include "./utils.h"

int main(void) {
    char *word = "moi";
    char *word2 = "lui";
    my_strcat(word ,word2);
    printf("mot final %s :",word);
    return EXIT_SUCCESS;
}