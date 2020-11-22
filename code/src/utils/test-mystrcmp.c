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
    char *mot3="moi";
    printf("Passage du premier test entre '%s'et '%s'\n",mot1,mot2);
    printf("test bool : %d \n",mystrcmp(mot1,mot2));
    printf("Passage du second test entre '%s' et '%s'\n",mot1,mot3);
    printf("test bool : %d \n",mystrcmp(mot1,mot3));
    return EXIT_SUCCESS;
}
