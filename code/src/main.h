#ifndef MAIN_H_
#define MAIN_H_

#include <yaml.h>
#include <array.h>
#include <utils.h>
#include <chiffreEnLettre.h>

/**
 * Affiche tous les yaml présent
 */
extern void affichageDialecte();

/**
 * Permet de lire un fichier de type yaml ET
 * l'ajoute dans une pile qui contient des structures de ChiffreEnLettre
 * @param array
 * @param dilacte
 */
extern void yaml(Array *array, char *dilacte);

/**
 *Permet de convertir un nombre en son équivalent en lettre
 * @param dialecte
 * @param nombre
 * @return
 */
extern char *conversion(char *dialecte, char *nombre);

/**
 *Permet de convertir une date en chiffre en son équivalent lettre
 * @param date
 * @return
 */
extern char *conversionDate(char *date);

/**
 *Permet convertir un chiffre en chiffre Romain
 * @param nombre
 * @return
 */
extern char *conversionRomain(char *nombre);

/**
 *Main du programme. Il prends deux arguments au lancement un dilacte et un nombre
 * Il donne en sortie le nombre en équivalent toute lettre dans le dialecte demander
 * @param argc
 * @param argv
 * @return
 */
extern int main(int argc, char *argv[]);

#endif //ARRAY_H_