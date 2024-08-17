#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char *argv[]){

    char *test[2];
    //creat a malloc space :
    for(int i=0;i<2;i++){
        test[i]=(char *)malloc(50*sizeof(char));

    }
    
    for (int i=0;i<2;i++){
        printf("give string %d : \n",i);
        scanf("%49[^\n]",test[i]);
        getchar();
    }
    //afficher the table :
    for (int i=0;i<2;i++){
        printf("%d : %s \n",i,test[i]);
    }
    //free malloc :
    for(int i=0;i<2;i++){
        free(test[i]);
    }



















}



