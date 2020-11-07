#include <ctype.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main(void){
char * dialecte = (char *) malloc (15);
dialecte = "FR_fr";

printf("dialecte : %s \n",dialecte);

strcpy(dialecte,".yaml");
printf("feuille : %s",dialecte);


return 0;
}
