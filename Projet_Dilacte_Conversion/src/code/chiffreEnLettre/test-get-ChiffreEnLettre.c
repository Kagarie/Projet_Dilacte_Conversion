#include <stdlib.h>

#ifdef NDEBUG
#undef NDEBUG
#endif

#include <assert.h>
#include <stdio.h>
#include "./chiffreEnLettre.inc"
#include "./chiffreEnLettre.h"

int main(void) {
    ChiffreEnLettre *ch = chiffreEnLettre_create_full(4, "test");
    printf("nombre : %d\n",chiffreEnLettre_get_nombre(ch));
    puts("Test get mot résussie");
    printf("mot : %s\n",chiffreEnLettre_get_mot(ch));
    puts("Test get nombre réussie");
    chiffreEnLettre_destroy(ch);
    return EXIT_SUCCESS;
}
