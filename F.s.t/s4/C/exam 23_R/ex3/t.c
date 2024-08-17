#include<stdio.h>
void ex1(int *x,int *y);
void ex2(int *x,int *y);
int main(){
    int x=0;
    printf("give x : ");
    scanf("%d",&x);
    int y=0;
    printf("give y : ");
    scanf("%d",&y);

    ex1(&x,&y);
    printf("x= %d , y= %d \n",x,y);
    ex2(&x,&y);
    printf("x= %d , y= %d ",x,y);

return 0;
}
void ex1(int *x,int *y){
    *x=*x+*y;
    *y=*x-*y;
    *x=*x-*y;
}
void ex2(int *x,int *y){
    *x=*x-*y;
    *y=*x+*y;
    *x=*y-*x;
}

