#include<stdio.h>
#include"fun.h"

int main(){

    int n=0;
    printf("give n : ");
    scanf("%d",&n);

    int result1=u(n);
    int result2=v(n);

    printf("U(n)=%d\n",result1);
    printf("V(n)=%d\n",result2);

    return 0;
}
