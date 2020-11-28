#include "chiffreEnLettre.h"

//Ceci est notre structre de base
struct _ChiffreEnLettre{
    int nombre;
    char* mot;
    ChiffreEnLettre *suivant;
};