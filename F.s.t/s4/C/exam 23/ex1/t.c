#include <stdio.h>
#include <stdlib.h>
#include "function.h"

int main(){
    int k=0;
    printf("give k le taile de table : ");
    scanf("%d",&k);


    int *t=remplir(k);
    afficher(t,k);
    printf("\n.......................\n");

    int k2=0;
    printf("give la taile de deplacment : ");
    scanf("%d",&k2);
    int *t2=deplacer(k2,t,k);

    printf("\n.......................\n");
    afficher(t2,k);
}

















