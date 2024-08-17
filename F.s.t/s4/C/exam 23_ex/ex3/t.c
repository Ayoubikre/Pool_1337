#include<stdio.h>
#include<time.h>
#include<stdlib.h>

int *tab(int n);

int main(){ 
    clock_t s1=clock();

    int n=0;
    printf("donner n : ");
    scanf("%d",&n);
    int *t=tab(n);

    clock_t s2=clock();

    double s3=((double)(s1+s2))/CLOCKS_PER_SEC;
    printf("le temp de extusion de se program : %f",s3);

    free(t);
    return 0;
}
int *tab(int n){
    int *t=malloc(n*sizeof(int));
    if(t==NULL){
        printf("error");
        return NULL;
    }
    srand(time(0));
    for(int i=0;i<n;i++){
        t[i]=rand()%1000;
    }

    return t;
}
