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
    printf("%d\n", numberToLetter_get_number(array->first));
    //assert(array_get_number(array) == 0);
    NumberToLetter *nb = numberToLetter_get_next(array->first);
    if (nb != NULL)
        printf("%s",numberToLetter_get_word(nb));
    //assert(array_get_word(array)==NULL);
    free(array);
    return EXIT_SUCCESS;
}
