#include <stdio.h>
#include <string.h>
#include <yaml.h>

//ma fonction pour voir si deux string sont egal 
int static mystrcmp(const char* s1, const char* s2){
    int i = 0;
    do
    {
        if (s1[i] != s2[i])
            return 1;
        i++;
    }
    while (s1[i-1] != 0);
    return 0;
}
int main(void) {
    //ouverture du fichier
    FILE* fh = fopen("FR_fr.yaml", "r");

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

    char* tk;
    //on boucle tout le long du fichier
    do {
        yaml_parser_scan(&parser, &token);
        switch(token.type) {
            /*il existe d'autre méthode mais dans autre cas seul 
            le YAML_SCALAR_TOKEN nous intéresse*/
                case YAML_SCALAR_TOKEN: 
                //on récupére chaques éléments du fichier 
                tk=token.data.scalar.value;

                /*le premier élèment récupérer et le nom du dialecte
                dans autre cas il nouos servira plus donc on traite ce cas*/
                    if(mystrcmp(tk,"FR_fr")==0){
                        puts("premier élèment");
                    }else{
                        //on s'occupe ensuite des éléèments qui nous interresse 
                        printf("%s ", tk);
                    }
                 break;
           default:break;
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