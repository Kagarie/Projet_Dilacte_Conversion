#include <stdlib.h>

#ifdef NDEBUG
#undef NDEBUG
#endif

#include <assert.h>
#include <stdio.h>
#include "./numberToLetter.inc"
#include "./numberToLetter.h"

int main(void) {
    char *word = "test";
    NumberToLetter *ch = numberToLetter_create_full(4, word);
    assert(ch->number == 4);
    assert(ch->word == "test");
    numberToLetter_destroy(ch);
    return EXIT_SUCCESS;
}
