#include <stdlib.h>

#ifdef NDEBUG
#undef NDEBUG
#endif

#include <assert.h>
#include <stdio.h>
#include "./array.inc"
#include "./array.h"

int main(void) {
    Array *array = array_initialisation();
    printf("%d\n", chiffreEnLettre_get_nombre(array->premier));
    //assert(array_get_nombre(array) == 0);
    ChiffreEnLettre *ch = chiffreEnLettre_get_suivant(array->premier);
    if (ch != NULL)
        printf(chiffreEnLettre_get_mot(ch));
    //assert(array_get_mot(array)==NULL);
    free(array);
    return EXIT_SUCCESS;
}
