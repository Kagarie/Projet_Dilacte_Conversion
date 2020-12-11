#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <dirent.h>
#include <assert.h>

#include "./main.h"

void static usage() {
    puts("Le programme s'utilise de la manière suivante.\n./convertisseur {--dialecte , nombre}\n");
    puts("Vous pouvez aussi utiliser les options suivantes.\n-c -commande pour voir les commandes disponible.");
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

char *conversion(char *dialecte, char *nombre) {

    //pour commencer on initialise nos array(s)
    Array *arrayReference = array_initialisation();
    Array *arrayDilacte = array_initialisation();

    //Le dilacte FR_fr nous servira de référence
    //Et on charge le dialecte demandé
    yaml(arrayReference, "FR_fr");
    yaml(arrayDilacte, dialecte);

    char *res = " ";
    int suivant = 1;
    for (int k = strlen(nombre); k > 0; k--) {
        suivant = 1;
        printf("k : %d\n", k);
        ChiffreEnLettre *ch = array_get_premier(arrayDilacte);
        while (ch != NULL) {
            if (atoi(nombre) == chiffreEnLettre_get_nombre(ch)) {
                res = chiffreEnLettre_get_mot(ch);
                //strcat(res, chiffreEnLettre_get_mot(ch));
                //res=chiffreEnLettre_get_mot(ch);
                // printf("res : %s\n", res);
                suivant = 0;
                break;
            }
            ch = chiffreEnLettre_get_suivant(ch);
        }

        if (suivant == 1) {
            ChiffreEnLettre *ref = array_get_premier(arrayReference);
            while (ref != NULL) {
                if (atoi(nombre) == chiffreEnLettre_get_nombre(ref)) {
                    res = chiffreEnLettre_get_mot(ref);
                    break;
                }
                ref = chiffreEnLettre_get_suivant(ref);

            }
        }
        strcat(res, " ");
    }

    array_destroy(arrayReference);
    array_destroy(arrayDilacte);
    return res;
}

char *conversionDate(char *date) {

}

char *conversionRomain(char *nombre) {

}

int main(int argc, char *argv[]) {
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
    if (strtol(argv[2], NULL, 0) == 0) {
        printf("entier attendu\n");
        exit(EXIT_FAILURE);
    }
    // si le test précédent march on récupérer la valeur par précotion on la "nettoie"
    char *dilacte;
    dilacte = strtok(argv[1], "--");
    char *nombre = argv[2];

    if (mystrcmp(dilacte, "date") == 0) {
        printf("date %s = %s\n", nombre, conversionDate(nombre));
    } else if (mystrcmp(dilacte, "romain") == 0) {
        printf("Nombre de départ: %s conversion: %s\n", nombre, conversionRomain(nombre));
    } else {
        printf("Nombre de départ: %s conversion: %s\n", nombre, conversion(dilacte, nombre));
    }
    return EXIT_SUCCESS;
}