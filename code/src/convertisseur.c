#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#include "./convertisseur.h"

//tableau des différents dialecte
static  char *dilacte;
dilacte=malloc(2 *sizeof(char));
dilacte[]={"FR_fr","FR_be"}

//fonction pour afficher les dilacte disponible
void static affichageDesDilacteDiponible(){
    puts("listes des dialectes disponible");
    for(int i = 0 ; i<sizeof(*dilacte)-1 ;i++)
        printf("%s\n",dilacte[i]);
}

//explication de l'utilisation de la librairy
void static usage(){
    puts("La librairy s'utilise de la manière suivante\n./convertisseur [char , int]\n");
    puts("Vous pouvez aussi utiliser les options suivantes\n-c -commande pour voir les commandes disponible");
    puts("-d -dilactes pour voir les dilactes disponible");
    exit(EXIT_SUCCESS);
}

//fonction pour vérifier que deux chaines soient exactement identique
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
//on vérifie si le dilacte est bien présent 
bool static verifDilacte(char* commande){
        int i = 0 ; 
        bool present =false;
        while(i<sizeof(dilacte) || present){
            if(mystrcmp(commande,dilacte[i])==0){
            present=true;
            }
            i+=1;
        }
        //si le dilacte n'est pas présent on affiche les dilactes présent et on sort du programme
        if(!present){
        puts("dilacte attendu");
        affichageDesDilacteDiponible();
        return false;
        }
    //si le dilacte et présent on peut continuer le traitement
    return true;
    }

int main (int argc, char* argv[]){
    //dans le premier cas on test si argc vaut 1 './programme' si oui on affiche comment utiliser la librayrie
    //Sinon on test si une commande est passé en paramètre 
   if(argc == 1 || mystrcmp(argv[1],"-c") ==0|| mystrcmp(argv[1],"-commande")==0){
     usage();
    }
    if(mystrcmp(argv[1],"-d") ==0|| mystrcmp(argv[1],"-dilactes")==0){
        affichageDesDilacteDiponible();
    }
  
    //Si le paramètre n'est pas une commande on test si c'est un dilacte 
    //Si ce n'est pas un dilacte et ni une commande on arrête le programme
    if(!verifDilacte(argv[1])){
        exit(EXIT_FAILURE);
    }
       
    //si le second paramètre n'est pas un entier on arrête le programme
    if( strtol(argv[2],NULL,0) == 0){
        printf("entier attendu\n");
        exit(EXIT_FAILURE);
    }

    /*
        Si tous les tests précédents sont bien passé nous pouvons passé en 
        phase de la traitement de la demande 
    */
   puts("ok");
return EXIT_SUCCESS;
}