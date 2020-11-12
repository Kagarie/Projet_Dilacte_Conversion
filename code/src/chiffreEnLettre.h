typedef  struct TabChiffreLettre TabChiffreLettre;
struct TabChiffreLettre{
    int index;
    struct* ChiffreLettre[];
};

typedef struct ChiffreLettre ChiffreLettre;
struct ChiffreLettre
{
    int nombre;
    char nombreEnLettre;
};