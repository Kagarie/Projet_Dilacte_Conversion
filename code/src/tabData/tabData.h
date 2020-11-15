#ifndef TABDATA_H_
#define TABDATA_H_
#include <stddef.h>
#include <stdlib.h>
typedef struct _TabData TabData;

//Creation de la scruture qui pointe sur des structures de ChiffreEnLettre
extern TabData *tabData_create(const unsigned int index, const unsigned int nombre,char* mot);

extern void tabData_destroy(TabData *tabData);

//On retourne l'index
extern unsigned int tabData_get_index(const TabData *tabData);

//On retourne le nombre de la sous-structure
extern unsigned int tabData_get_nombre(const TabData *tabData);

//On retourne le mot de la sous-structure
extern char *tabData_get_mot(const TabData *tabData);

#endif //TABDATA_H_