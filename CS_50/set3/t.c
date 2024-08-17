#include <stdio.h>
#include <stdint.h>
#include<string.h>
#include <stdlib.h>


int main(int argc,char*argv[]){
    // if(argc!=2){
    //     printf("usage : ./t doc.txt");
    //     return 1;
    // }
    FILE* f1_r=fopen(argv[1],"r");
    if(f1_r==NULL){
        printf("error in file f1");
        return 1;
    }
    char *test[10]=malloc(10*sizeof(char));
    for(int i=0;i<10;i++){
    fscanf(f1_r,"%s",test[i]);
    printf("%s\n",test[i]);
    }
}







