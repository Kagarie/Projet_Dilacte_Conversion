#include <stdlib.h>

#ifdef NDEBUG
#undef NDEBUG
#endif

#include <assert.h>
#include <stdio.h>
#include "./chiffreEnLettre.inc"
#include "./chiffreEnLettre.h"

int main(void) {
    char *mot = "test";
    char *test = "faux";
    ChiffreEnLettre *ch = chiffreEnLettre_create_full(4, mot);
    assert(ch->nombre == 4);
   // assert(ch->mot == test);
    chiffreEnLettre_destroy(ch);
    return EXIT_SUCCESS;
}
