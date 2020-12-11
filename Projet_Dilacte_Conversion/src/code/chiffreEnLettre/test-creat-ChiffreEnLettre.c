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
    printf("Test du nombre réussie\n");
    assert(ch->mot == "test");
    printf("Test du mot réussie\n");
    chiffreEnLettre_destroy(ch);
    printf("Structure détruite\n");
    return EXIT_SUCCESS;
}
