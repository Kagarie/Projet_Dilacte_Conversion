#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#include "./convertisseur.h"

//tableau des différents dialecte
static  char *dialecte;
dialecte=malloc(2 *sizeof(char));
dialecte[]={"FR_fr","FR_be"}

//fonction pour afficher les dialecte disponible
void static affichageDesDilacteDiponible(){
    puts("listes des dialectes disponible");
    for(int i = 0 ; i<sizeof(*dialecte)-1 ;i++)
        printf("%s\n",dialecte[i]);
}

//explication de l'utilisation de la librairy
void static usage(){
    puts("La librairy s'utilise de la manière suivante\n./convertisseur [--dialecte , int]\n");
    puts("Vous pouvez aussi utiliser les options suivantes\n-c -commande pour voir les commandes disponible");
    puts("-d -dialecte pour voir les dialecte disponible");
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
//on vérifie si le dialecte est bien présent 
bool static verifDialecte(char* commande){
        int i = 0 ; 
        bool present =false;
        while(i<sizeof(dialecte) || present){
            if(mystrcmp(commande,dialecte[i])==0){
            present=true;
            }
            i+=1;
        }
        //si le dialecte n'est pas présent on affiche les dialectes présent et on sort du programme
        if(!present){
        puts("dialecte attendu");
        affichageDesDilacteDiponible();
        return false;
        }
    //si le dialecte et présent on peut continuer le traitement
    return true;
    }

int main (int argc, char* argv[]){
    
    //dans le premier cas on test si argc vaut 1 './programme' si oui on affiche comment utiliser la librayrie
    //Sinon on test si une commande est passé en paramètre 
   if(argc == 1 || mystrcmp(argv[1],"-c") ==0|| mystrcmp(argv[1],"-commande")==0){
     usage();
    }
    if(mystrcmp(argv[1],"-d") ==0|| mystrcmp(argv[1],"-dialecte")==0){
        affichageDesDilacteDiponible();
    }
  
    //Si le paramètre n'est pas une commande on test si c'est un dialecte 
    //Si ce n'est pas un dialecte et ni une commande on arrête le programme
    if(!verifDialecte(argv[1])){
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
  
return EXIT_SUCCESS;
}