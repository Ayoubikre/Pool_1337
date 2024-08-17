#include<stdio.h>
#include<string.h>
#include<stdlib.h>

// sorting city based of temp

//creating a struct of city
typedef struct t{
    char name[20];
    int tmp;
}temp;
temp t[3];
int count;

// taking input 
void sorting();
int main(){
  printf("how mutch you want to compare : ");
  scanf("%d",&count);
    for(int i=0;i<count;i++){
        printf("give the city name : ");
        scanf(" %19s",t[i].name);
        printf("give the tmp : ");
        scanf(" %d",&t[i].tmp);
    }
    sorting();
    printf("result :\n");
    for(int i=0;i<count;i++){
        printf("%s : ",t[i].name);
        printf("%d \n",t[i].tmp);

    }
}

//sorting city based of temp
void sorting(){
    temp test;
    for(int i=0;i<count;i++){
        for(int j=1;j<count-i;j++){
            if(t[j-1].tmp>t[j].tmp){
                test=t[j];
                t[j]=t[j-1];
                t[j-1]=test;
            }
        }
    }
}
