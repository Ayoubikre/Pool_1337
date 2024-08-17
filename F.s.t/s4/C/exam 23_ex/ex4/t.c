#include<stdio.h>

void switch1(int *a,int*b);
void switch2(int *a,int*b);

int main(){
    int a=0;
    printf("give a : ");
    scanf("%d",&a);
    int b=0;
    printf("give b : ");
    scanf("%d",&b);

    switch1(&a,&b);
    switch2(&a,&b);

}
void switch1(int *a,int*b){
    *a=*a+*b;
    *b=*a-*b;
    *a=*a-*b;
    printf("a = %d\n",*a);
    printf("b = %d\n",*b);  
}
void switch2(int *a,int*b){
    *b=*a+*b;
    *a=*b-*a;
    *b=*b-*a;
    printf("a = %d\n",*a);
    printf("b = %d\n",*b);  

}