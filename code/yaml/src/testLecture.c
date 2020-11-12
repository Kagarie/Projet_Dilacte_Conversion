#include <stdio.h>
#include <string.h>
#include <yaml.h>

//ma fonction pour voir si deux string sont egal 
int static mystrcmp(const char *s1, const char *s2) {
    int i = 0;
    do {
        if (s1[i] != s2[i])
            return 1;
        i++;
    } while (s1[i - 1] != 0);
    return 0;
}

// ma propre function strcat
char *my_strcat(char *destination, const char *source) {
    //calcul de la longueur minimum
    char *ptr = destination + strlen(destination);

    // Appends characters of source to the destination string
    while (*source != '\0')
        *ptr++ = *source++;

    // ajout du caractère de fin de chaines
    *ptr = '\0';
    // on retourne la resultat des chaines
    return destination;
}

int main(void) {

    char *str = (char *) calloc(20, 1);
    char *diallect = "FR_fr";
    my_strcat(str, diallect);
    my_strcat(str, ".yaml");
    //ouverture du fichier
    FILE *fh = fopen(str, "r");

    //on vérifie si le fichier à bien était ouvert
    if (fh == NULL)
        fputs("Erreur ouvertur yaml!\n", stderr);

    //initialisation du parser et token
    yaml_parser_t parser;
    yaml_token_t token;

    //erreur si l'initialisation échoue
    if (!yaml_parser_initialize(&parser))
        fputs("Erreur initialisation parser!\n", stderr);

    //on place le paser au début du fichier à lire
    yaml_parser_set_input_file(&parser, fh);

    //on récupére les données
    char *tk;
    //on boucle tout le long du fichier
    do {
        yaml_parser_scan(&parser, &token);
        switch (token.type) {
            /*il existe d'autre méthode mais dans autre cas seul 
            le YAML_SCALAR_TOKEN nous intéresse*/
            //  case YAML_SCALAR_TOKEN:
            //on récupére chaques éléments du fichier

            //tk=token.data.scalar.value;
            /*le premier élèment récupérer et le nom du dialecte
            dans autre cas il nouos servira plus donc on traite ce cas*/
            /*if(mystrcmp(tk,"FR_fr")==0){
                puts("premier élèment");
            }else{
                //on s'occupe ensuite des éléèments qui nous interresse
                printf(" test 1 : %s ", tk);
                token.type;
                tk=token.data.scalar.value;
                printf("test 2 : %s",tk);
            }*/
            /*    break;
            case YAML_KEY_TOKEN:
                tk=token.data.scalar.value;
                printf("Key token : %s",tk);
                break;
            case YAML_VALUE_TOKEN:
                //printf("(Value token) ");
                break;
            default:
                break;*/

/* Data */
            case YAML_SCALAR_TOKEN:
                printf("%s \n", token.data.scalar.value);
                tk = token.data.scalar.value;
                break;

/* Token types (read before actual token) */
            case YAML_KEY_TOKEN:
            printf("Key token tk : %s et %s");
                break;
            case YAML_VALUE_TOKEN:
                //printf("(Value token) ");
                printf("(Value token) ");
                break;

/* Others */
            default:
                printf("Got token of type %d\n", token.type);


        }
        if (token.type != YAML_STREAM_END_TOKEN)
            yaml_token_delete(&token);
    } while (token.type != YAML_STREAM_END_TOKEN);
    puts("");
    //on libère notre token et notre parser
    yaml_token_delete(&token);
    yaml_parser_delete(&parser);
    //on en a fini avec le fichier
    fclose(fh);

    return EXIT_SUCCESS;
}