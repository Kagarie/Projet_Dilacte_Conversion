#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <dirent.h>

#include "./main.h"

void static usage() {
    puts("Le programme s'utilise de la manière suivante\n./convertisseur [--dialecte , int]\n");
    puts("Vous pouvez aussi utiliser les options suivantes\n-c -commande pour voir les commandes disponible");
    puts("-d -dilacte pour voir les dialecte disponible");
}

void affichageDialecte() {
    struct dirent *dir;
    // opendir() renvoie un pointeur de type DIR.
    DIR *d = opendir("yaml/");
    if (d) {
        while ((dir = readdir(d)) != NULL) {
            if (mystrcmp(dir->d_name, ".") && mystrcmp(dir->d_name, "..")) {
                fprintf(stdout, " Dilacte :%s \n", dir->d_name);
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
    FILE *fh = fopen(str, "r");

    //on vérifie si le fichier à bien était ouvert
    if (fh == NULL) {
        fputs("Erreur ouvertur yaml!\n", stderr);
        exit(EXIT_FAILURE);
    }

    yaml_parser_t parser;
    yaml_token_t token;   /* new variable */

    /* Initialize parser */
    if (!yaml_parser_initialize(&parser))
        fputs("Failed to initialize parser!\n", stderr);
    if (fh == NULL)
        fputs("Failed to open file!\n", stderr);

    /* Set input file */
    yaml_parser_set_input_file(&parser, fh);


    char *mot;
    char *nombre;
    /* BEGIN new code */
    do {
        yaml_parser_scan(&parser, &token);
        switch (token.type) { ;
/* Token types (read before actual token) */
            case YAML_KEY_TOKEN:
                printf("(Key token)  ");
                nombre = token.data.scalar.value;
                printf("nombre %s\n", token.data.scalar.value);

                break;
            case YAML_VALUE_TOKEN:
                printf("(Value token) ");
                mot = token.data.scalar.value;
                break;
/* Data */
            case YAML_SCALAR_TOKEN:
                if (token.type == YAML_KEY_TOKEN) {
                    nombre = token.data.scalar.value;
                }
                if (token.type = YAML_VALUE_TOKEN) {
                    mot = token.data.scalar.value;
                }
                if (mystrcmp(token.data.scalar.value, dilacte) != 0)
                    printf("scalar %s \n", token.data.scalar.value);
                //printf("mot %s  et nombre %s\n",mot,nombre);
                break;

        }
        if (token.type != YAML_STREAM_END_TOKEN)
            yaml_token_delete(&token);
    } while (token.type != YAML_STREAM_END_TOKEN);
    yaml_token_delete(&token);
/* END new code */

/* Cleanup */
    //free(str);
    yaml_parser_delete(&parser);
    fclose(fh);

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

    /*
        Si tous les tests précédents sont bien passé nous pouvons passer en
        phase de traitement de la demande

        Dans premier temps on charge dans un tableau le dilacte par défaut
        Puis dans un second tableau le dilacte demandé
        Après on traite la demande si ce n'est pas présent dans le dilacte demandé on va chercher dans le tableau par défaut
    */


    const char s[3] = "--";
    char *dilacte;
    dilacte = strtok(argv[1], s);
    int nombre = strtol(argv[2], NULL, 0);


    //pour commencer on initialise notre array
    Array *arrayReference = array_initialisation();
    Array *arrayDilacte = array_initialisation();

    //le dilacte FR_fr nous servira de référence
    //il permet de faire une array qui contient des structures
    yaml(arrayReference, "FR_fr");

    //Puis on charge le dilacte demandé
    yaml(arrayDilacte, dilacte);

    // Exemple de parcours de l'array Gabriel
    //array_affiche(arrayReference);


    //A ce moment la nous avons deux dilacte de charger (la référence et la demande)
    //On peut donc effectuer la demande

    array_destroy(arrayReference);
    array_destroy(arrayDilacte);
    return EXIT_SUCCESS;


}
