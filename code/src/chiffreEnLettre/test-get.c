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
    ChiffreEnLettre *ch = chiffreEnLettre_create_full(4, mot);
    printf("nombre :%d\n",chiffreEnLettre_get_nombre(ch));
    printf("mot :%s",chiffreEnLettre_get_mot(ch));
    chiffreEnLettre_destroy(ch);
    return EXIT_SUCCESS;
}
