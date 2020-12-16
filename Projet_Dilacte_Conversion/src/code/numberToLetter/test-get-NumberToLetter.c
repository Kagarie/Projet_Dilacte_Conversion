#include <stdlib.h>

#ifdef NDEBUG
#undef NDEBUG
#endif

#include <assert.h>
#include <stdio.h>
#include "./numberToLetter.inc"
#include "./numberToLetter.h"

int main(void) {
    NumberToLetter *ch = numberToLetter_create_full(4, "test");
    printf("nombre : %d\n",numberToLetter_get_number(ch));
    printf("mot : %s\n",numberToLetter_get_word(ch));
    numberToLetter_destroy(ch);
    return EXIT_SUCCESS;
}
