#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <yaml.h>

#include "./tabData/tabData.h"
#include "./utils/utils.h"


//explication de l'utilisation de la librairy
void static usage() {
    puts("La librairy s'utilise de la manière suivante\n./convertisseur [--dialecte , int]\n");
    puts("Vous pouvez aussi utiliser les options suivantes\n-c -commande pour voir les commandes disponible");
    puts("-d -dialecte pour voir les dialecte disponible");
    exit(EXIT_SUCCESS);
}

//a faire
void affichageDialecte(const char *dialect[]) {

}

//on vérifie si le dialecte est bien présent
bool static verifDialecte(char *commande) {
    int i = 0;
    bool present = false;
    //refaire cette fonction après avoir fini avec le tableau
    /*while(i<sizeof(dialecte) || present){
        if(mystrcmp(commande,dialecte[i])==0){
        present=true;
        }
        i+=1;
    }*/
    //si le dialecte n'est pas présent on affiche les dialectes présent et on sort du programme
    if (!present) {
        puts("dialecte attendu");
        return false;
    }
    //si le dialecte et présent on peut continuer le traitement
    return true;
}

void yaml(const char *dialecte) {
    //création du nom de feuille à chercher
    char *str = (char *) calloc(20, 1);
    my_strcat(str, dialecte);
    my_strcat(str, ".yaml");
    //ouverture du fichier
    FILE *fh = fopen(str, "r");

    //on vérifie si le fichier à bien était ouvert
    if (fh == NULL)
        fputs("Error  open yaml!\n", stderr);

    //initialisation du parser et token
    yaml_parser_t parser;
    yaml_token_t token;

    //erreur si l'initialisation échoue
    if (!yaml_parser_initialize(&parser))
        fputs("Erreur initialisation parser!\n", stderr);

    //on place le paser au début du fichier à lire
    yaml_parser_set_input_file(&parser, fh);

    //si tout c'est bien passé on peux déclarer nos structure
   /* struct TabChiffreLettre tabData;
    tabData.index = 0;
    struct ChiffreLettre chifData;
    */
    //on déclare aussi une variable qui va nous servir à récupérer les données
    char *tk;
    //on boucle tout le long du fichier
    do {
        yaml_parser_scan(&parser, &token);
        switch (token.type) {
            /*il existe d'autre méthode mais dans autre cas seul
            le YAML_SCALAR_TOKEN nous intéresse*/
            case YAML_SCALAR_TOKEN:
                //on récupére chaques éléments du fichier
                tk = token.data.scalar.value;
                /*le premier élèment récupérer et le nom du dialecte
                dans autre cas il nouos servira plus donc on traite ce cas*/

                //tabData.index += 1;

                break;
                /* Token types (read before actual token) */
            case YAML_KEY_TOKEN:
                if (mystrcmp(tk, dialecte) == 0)
                    puts("premier élèment");
                else {
                    //on s'occupe ensuite des éléèments qui nous interresse
                    printf("%s ", tk);
                    //chifData.nombre = tk;
                }
                break;
            case YAML_VALUE_TOKEN:
                //printf("(Value token) ");
                printf("(Value token) ");
                //chifData.nombreEnLettre = tk;
                break;
            default:
                break;
        }
        if (token.type != YAML_STREAM_END_TOKEN)
            yaml_token_delete(&token);
    } while (token.type != YAML_STREAM_END_TOKEN);
    //on libère notre token et notre parser
    yaml_token_delete(&token);
    yaml_parser_delete(&parser);
    //on en a fini avec le fichier
    fclose(fh);
}

int main(int argc, char *argv[]) {

    //dans le premier cas on test si argc vaut 1 './programme' si oui on affiche comment utiliser la librayrie
    //Sinon on test si une commande est passé en paramètre
    if (argc == 1 || mystrcmp(argv[1], "-c") == 0 || mystrcmp(argv[1], "-commande") == 0) {
        usage();
    }
    if (mystrcmp(argv[1], "-d") == 0 || mystrcmp(argv[1], "-dialecte") == 0) {
        // affichageDesDilacteDiponible();
    }

    //Si le paramètre n'est pas une commande on test si c'est un dialecte
    //Si ce n'est pas un dialecte et ni une commande on arrête le programme
    if (!verifDialecte(argv[1])) {
        exit(EXIT_FAILURE);
    }

    //si le second paramètre n'est pas un entier on arrête le programme
    if (strtol(argv[2], NULL, 0) == 0) {
        printf("entier attendu\n");
        exit(EXIT_FAILURE);
    }
    /*
        Si tous les tests précédents sont bien passé nous pouvons passer en
        phase de traitement de la demande

        Dans premier temps on charge dans un tableau le dilacte par défaut
        Puis dans un second tableau le dilacte demandé
        Après on traite la demande si ce n'est pas présent dans le dilacte demandé on va chercher dans le tableau par défaut
    */

    printf("test : ", argv[1]);
    //le dilacte FR_fr nous servira de référence
    yaml("FR_fr");

    return EXIT_SUCCESS;
}