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
    char *word3 = "moi";
    printf("First test '%s'and '%s'\n", word, word2);
    printf("test bool : %d \n", mystrcmp(word, word2));
    printf("Second test '%s' et '%s'\n", word, word3);
    printf("test bool : %d \n", mystrcmp(word, word3));
    return EXIT_SUCCESS;
}
