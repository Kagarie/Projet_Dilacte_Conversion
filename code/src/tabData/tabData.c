#include "./tabData.h"
#include "tabData.inc"


TabData *tabData_create(const unsigned int index, const unsigned int nombre,char* mot) {
    TabData *tabData = malloc(sizeof(TabData));
    if (tabData) {
        tabData->index = index;
        tabData->chiffreEnLettre = chiffreEnLettre_create_full(nombre, mot);
        if (!tabData->chiffreEnLettre) {
            free(tabData);
            tabData = NULL;
        }
    }
    return tabData;
}

void tabData_destroy(TabData *tabData) {
    chiffreEnLettre_destroy(tabData->chiffreEnLettre);
    free(tabData);
}

unsigned int tabData_get_index(const TabData *tabData) {
    return tabData->index;
}

unsigned int tabData_get_nombre(const TabData *tabData) {
    return chiffreEnLettre_get_nombre(tabData->chiffreEnLettre);
}

char *tabData_get_mot(const TabData *tabData) {
    return chiffreEnLettre_get_mot(tabData->chiffreEnLettre);
}