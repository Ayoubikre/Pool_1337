#include<stdio.h>
#include"suit.h"

int main(){ 
    int n=0;
    printf("doonner n : ");
    scanf("%d",&n);
    int rs1=Un(n);
    int rs2=Vn(n);

    printf("resulta de fonction Un(%d) = %d\n",n,rs1);
    printf("resulta de fonction Un(%d) = %d\n",n,rs2);

return 0;
}
