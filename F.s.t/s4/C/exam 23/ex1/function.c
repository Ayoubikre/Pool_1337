#include<stdio.h>
#include<time.h>
#include<stdlib.h>

int *remplir(int n){
    int*t=malloc(n*sizeof(int));
        if(t==NULL){
            printf("error in aloccating memories");
            return NULL;
        }
    srand(time(0));
    for(int i=0;i<n;i++){
        t[i]=rand()%101;
    }

    return t;
}
void afficher(int t[],int n){
    for(int i=0;i<n;i++){
        printf("%d\n",t[i]);
    }
}
int* deplacer(int k,int t[],int n){

    for(int i=0;i<k;i++){
        int tmp=t[n-1];
        for(int j=n-2;j>=0;j--){
            t[j+1]=t[j];
        } 
        t[0]=tmp; 
    }
    
    return t;
}

