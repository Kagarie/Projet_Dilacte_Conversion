#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#include "./convertisseur.h"

//tableau des différents dialecte
//#define char tab[];

int static mystrcmp(const char* s1, const char* s2)
{
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
void static usage(){
    puts("La librairy s'utilise de la manière suivante\n./convertisseur [char , int]\n");
    puts("Vous pouvez aussi utiliser les options suivantes\n-c -commande pour voir les commandes disponible");
    puts("-d -dilactes pour voir les dilactes disponible");
    exit(EXIT_SUCCESS);
}

void static charAttendu(){

    exit(EXIT_FAILURE);
}

void static entierAttendu(){


    exit(EXIT_FAILURE);
}

void static affichageDesDialecteDiponible(){
    puts("listes des dialectes disponible");
    /*for(int i = 0 ; i<tab;i+=1)
    printf("%s",tab[i]);*/
    exit(EXIT_SUCCESS);
}

int main (int argc, char* argv[]){
    
    // test si commande passé en paramètre 
    if(argc == 1 || mystrcmp(argv[1],"-c") ==0|| mystrcmp(argv[1],"-commande")==0){
     usage();
    }
    if(mystrcmp(argv[1],"-d") ==0|| mystrcmp(argv[1],"-dilactes")==0){
        affichageDesDialecteDiponible();
    }
    /*
    if (argc ==3 &&){
    // si le premier paramètre n'est pas un char erreur
    if(argv[1]==char){
        //test si le dialecte passe et bien present dans la liste des dialectes disponible
        int i = 0 ; 
        bool present =false;
        while(i<tab[] || present){
            if(argv[1]==tab[i]){
            present=true;
            }
        }
        if(!present){
            puts("dilacte non présente");

        }
        
    }else{
     puts("dilacte attendu");
     affichageDesDialecteDiponible();
    }
    
    }
    

    //si le second paramètre n'est pas un entier erreur
    if(argv[2]== int){
        entierAttendu();
    }
    */

return EXIT_SUCCESS;
}