#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <dirent.h>
#include <assert.h>

#include "./main.h"


void static usage() {
    puts("Le programme s'utilise de la manière suivante.\n./main {--dialecte , nombre}\n");
    puts("Vous pouvez aussi convertir un date.\n./main --date 01/01/1970\n");
    puts("Mais aussi les chiffres romain.\n./main {--Romain,nombre}\n");
    puts("Vous pouvez utiliser les options suivantes.\n-c -commande pour voir les commandes disponible.");
    puts("-d -dilacte pour voir les dialectes disponible.\n");
    puts("Notre convertisseur marche pour les nombre compris en 0 et 1000.");
    puts("Si le résultat est null alors votre nombre n'a pas pu être convertie.");
}

void affichageDialecte() {
    char *dialecte;
    struct dirent *dir;
    // opendir() renvoie un pointeur de type DIR.
    DIR *d = opendir("yaml/");
    if (d) {
        while ((dir = readdir(d)) != NULL) {
            if (mystrcmp(dir->d_name, ".") && mystrcmp(dir->d_name, "..")) {
                fprintf(stdout, " Dialecte : %s\n", dir->d_name);
            }
        }
        closedir(d);
    }

}

void yaml(Array *array, char *dilacte) {
    //création du nom de feuille à chercher
    char *str = (char *) calloc(20, 1);
    my_strcat(str, "yaml/");
    my_strcat(str, dilacte);
    my_strcat(str, ".yaml");

    //ouverture du fichier
    FILE *file = fopen(str, "rb");
    assert(file);

    //on vérifie si le fichier à bien était ouvert
    if (file == NULL) {
        fputs("Erreur ouvertur yaml!\n", stderr);
        exit(EXIT_FAILURE);
    }

    yaml_parser_t parser;
    yaml_document_t document;
    yaml_node_t *node;
    int i = 1;

    char *mot = NULL;
    char *nombre = NULL;

    assert(yaml_parser_initialize(&parser));

    yaml_parser_set_input_file(&parser, file);

    if (!yaml_parser_load(&parser, &document)) {
        goto done;
    }

    while (1) {
        node = yaml_document_get_node(&document, i);
        i++;
        if (!node) break;
        node->type;
        if (node->type == YAML_SCALAR_NODE) {
            if (strcmp(node->data.scalar.value, dilacte)) {
                if (node->data.scalar.style == 1) {
                    nombre = node->data.scalar.value;
                }
                if (node->data.scalar.style == 3) {
                    mot = node->data.scalar.value;
                }
                if (i % 2 == 0) {
                    array_insertion(array, atoi(nombre), mot);
                }
            }
        }
    }
    array_insertion(array, -1, NULL);
    //yaml_document_delete(&document);
    done:
    yaml_parser_delete(&parser);
    assert(!fclose(file));
}

int puissance(int x, int n) {
    int y = 1;
    unsigned int m = 1;
    while (m <= n) {
        y *= x;
        m++;
    }
    return y;
}

char *conversionReference(char *recherche) {
    Array *arrayReference = array_initialisation();
    yaml(arrayReference, "FR_fr");
    char *res = malloc(sizeof(char));
    res[0] = '\0';


    int i = strlen(recherche);
    int k = 0;
    int grandeur = i;
    while (i > 0) {
        grandeur = i;
        if (k == strlen(recherche) - 1 && atoi(&recherche[k]) == 0) {
            break;
        }

        if (recherche[k] == '1' && k != 2) {
            ChiffreEnLettre *ref = array_get_premier(arrayReference);
            while (ref != NULL) {
                if (puissance(10, i - 1) == chiffreEnLettre_get_nombre(ref)) {
                    strcat(res, chiffreEnLettre_get_mot(ref));
                    strcat(res, " ");
                }
                ref = chiffreEnLettre_get_suivant(ref);
            }
        } else {
            ChiffreEnLettre *ref = array_get_premier(arrayReference);
            while (ref != NULL) {
                if (i == 2) {
                    if (atoi(&recherche[k]) == chiffreEnLettre_get_nombre(ref) &&
                        recherche[k + 1] == '0') {
                        int dizaine = atoi(&recherche[k]) + atoi(&recherche[k + 1]);
                        int trouve = 0;
                        // printf("dizaine %d\n", dizaine);
                        puts(" ");
                        if (dizaine == chiffreEnLettre_get_nombre(ref)) {
                            strcat(res, chiffreEnLettre_get_mot(ref));
                            strcat(res, " ");
                            trouve = 1;
                            break;
                        }
                    }
                } else if (atoi(&recherche[k]) / puissance(10, i - 1) == chiffreEnLettre_get_nombre(ref) &&
                           recherche[k] != '0') {
                    strcat(res, chiffreEnLettre_get_mot(ref));
                    strcat(res, " ");
                    if (grandeur == 4) {
                        strcat(res, "milles ");
                    }
                    if (grandeur == 3) {
                        strcat(res, "cents ");
                    }
                }

                ref = chiffreEnLettre_get_suivant(ref);
            }
        }
        i -= 1;
        k += 1;
    }
    array_destroy(arrayReference);
    return res;
}

char *conversion(char *dialecte, char *nombre) {
    //Pour commencer on initialise notre array
    Array *arrayDialecte = array_initialisation();

    //Et on charge le dialecte demandé
    yaml(arrayDialecte, dialecte);

    char *res = malloc(sizeof(char));
    res[0] = '\0';

    if (atoi(nombre) == 0) {
        return "zéro";
    }
    // On s'occupe de convertir le jour
    int trouve = 0;
    ChiffreEnLettre *d = array_get_premier(arrayDialecte);
    while (d != NULL) {
        if (atoi(nombre) == chiffreEnLettre_get_nombre(d)) {
            strcat(res, chiffreEnLettre_get_mot(d));
            strcat(res, " ");
            trouve = 1;
            break;
        }
        d = chiffreEnLettre_get_suivant(d);
    }
    // l'element n'est pas present on cherche dans le dialecte de reference
    if (trouve == 0) {
        strcat(res, conversionReference(nombre));
    }

    array_destroy(arrayDialecte);
    return res;
}

char *conversionDate(char *date) {
    Array *arrayJour = array_initialisation();
    Array *arrayMois = array_initialisation();
    yaml(arrayJour, "Date_jour");
    yaml(arrayMois, "Date_mois");

    char *res = malloc(sizeof(char));
    res[0] = '\0';
    char *jour;
    char *mois;
    char *annees;

    //on decoupe la date
    for (int i = 0; i < 3; i += 1) {
        switch (i) {
            case 0:
                jour = strtok(date, "/");
                break;
            case 1:
                mois = strtok(NULL, "/");
                break;
            case 2:
                annees = strtok(NULL, " ");
                break;
            default:
                puts("Erreur dans la conversion de la date");
                exit(EXIT_FAILURE);
        }
    }
    //on verifie si la date est valide
    if (atoi(jour) < 0 || atoi(jour) > 31 || atoi(mois) < 0 || atoi(mois) > 12 || atoi(annees) < 0) {
        printf("Erreur dans la date saisie\n");
        exit(EXIT_FAILURE);
    }
    // On s'occupe de convertir le jour
    int trouve = 0;
    ChiffreEnLettre *j = array_get_premier(arrayJour);
    while (j != NULL) {
        if (atoi(jour) == chiffreEnLettre_get_nombre(j)) {
            strcat(res, chiffreEnLettre_get_mot(j));
            strcat(res, " ");
            trouve = 1;
            break;
        }
        j = chiffreEnLettre_get_suivant(j);
    }
    // l'element n'est pas present on cherche dans le dialecte de reference
    if (trouve == 0) {
        strcat(res, conversionReference(jour));
    }

    //le mois
    ChiffreEnLettre *m = array_get_premier(arrayMois);
    while (m != NULL) {
        if (atoi(mois) == chiffreEnLettre_get_nombre(m)) {
            strcat(res, chiffreEnLettre_get_mot(m));
            strcat(res, " ");
            break;
        }
        m = chiffreEnLettre_get_suivant(m);
    }
    //l'annee
    char *a = conversionReference(annees);
    res = realloc(res, strlen(res) + strlen(a));
    strcat(res, a);


    array_destroy(arrayJour);
    array_destroy(arrayMois);
    return res;
}

char *conversionRomain(char *nombre) {

    Array *arrayRomain = array_initialisation();
    yaml(arrayRomain, "romain");
    char *res = malloc(sizeof(char));
    res[0] = '\0';

    if (strlen(nombre) == 1 || strlen(nombre) == 2 && atoi(nombre) <= 16) {

        int trouve = 0;
        ChiffreEnLettre *romain = array_get_premier(arrayRomain);
        while (romain != NULL) {
            if (atoi(nombre) == chiffreEnLettre_get_nombre(romain)) {
                strcat(res, chiffreEnLettre_get_mot(romain));
                strcat(res, " ");
                trouve = 1;
                break;
            }
            romain = chiffreEnLettre_get_suivant(romain);
        }
        if (trouve == 0) {

            puts("Erreur rencontré lors la conversion");
            exit(EXIT_FAILURE);


        }

        array_destroy(arrayRomain);
        return res;

    } else if (strlen(nombre) == 2 && nombre[1] != 0) {
        char *premier = malloc(sizeof(char));
        premier[0] = nombre[0] * 10;
        printf("%s\n", nombre);
        char *premiernb = conversionRomain(premier);
        char *deuxiemenb = conversionRomain(&nombre[1]);
        char *res = malloc(sizeof(char));
        res[0] = *premiernb;
        strcat(res, deuxiemenb);
        array_destroy(arrayRomain);
        return res;


    }
}

int main(int argc, char *argv[]) {
    if (argc == 1) {
        usage();
        exit(EXIT_FAILURE);
    }
    //dans le premier cas on test si argc vaut 1 './programme' si oui on affiche comment utiliser la librayrie
    //Sinon on test si une commande est passé en paramètre
    if (mystrcmp(argv[1], "-c") == 0 || mystrcmp(argv[1], "-commande") == 0) {
        usage();
        exit(EXIT_SUCCESS);
    }
    if (mystrcmp(argv[1], "-d") == 0 || mystrcmp(argv[1], "-dilacte") == 0) {
        affichageDialecte();
        exit(EXIT_SUCCESS);
    }

    if (argc != 3) {
        usage();
        exit(EXIT_FAILURE);
    }


    //si le second paramètre n'est pas un entier on arrête le programme
    if (strtol(argv[2], NULL, 0) < 0) {
        printf("entier attendu\n");
        exit(EXIT_FAILURE);
    }
    // si le test précédent march on récupérer la valeur par précotion on la "nettoie"
    char *dilacte;
    dilacte = strtok(argv[1], "--");
    char *nombre = argv[2];
    if (atoi(nombre) > 9999) {
        puts("Nous n'acceptons pas les nombres supérieur à 9 999");
        exit(EXIT_FAILURE);
    }


    if (mystrcmp(dilacte, "date") == 0) {
        printf("date : %s\n", conversionDate(nombre));
    } else if (mystrcmp(dilacte, "romain") == 0) {
        printf("Nombre de départ: %s conversion: %s\n", nombre, conversionRomain(nombre));
    } else {
        printf("Nombre de départ: %s conversion: %s\n", nombre, conversion(dilacte, nombre));
    }
    return EXIT_SUCCESS;
}