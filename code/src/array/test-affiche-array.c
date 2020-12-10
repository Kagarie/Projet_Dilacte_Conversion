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
    char *cent = "cent";
    char *mille = "mille";
    assert(array_insertion(array, 10, "dix"));
    assert(array_insertion(array, 15, "quinze"));
    assert(array_insertion(array, 16, "seize"));
    assert(array_insertion(array, 100, cent));
    assert(array_insertion(array, 1000, mille));
    array_affiche(array);
    array_destroy(array);
    return EXIT_SUCCESS;
}
