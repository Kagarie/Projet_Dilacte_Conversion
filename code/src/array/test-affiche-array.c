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
    array_insertion(array, 15, "quinze");
    array_insertion(array, 16, "seize");
    array_insertion(array, 10, "dix");
    array_affiche(array);
    return EXIT_SUCCESS;
}
