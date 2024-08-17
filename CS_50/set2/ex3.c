#include<stdio.h>

int w,h;

//chaeck averege / total hours played 

int main (){
    printf("weeks numbers : ");
    scanf("%d",&w);
 int t[w];
    for(int i=0;i<w;i++){
        printf("hours in week %d : ",i+1);
        scanf("%d",&t[i]);
        getchar();

    }
 char ans;
    printf("Enter T for total hours, A for average hours per week: ");
    scanf("%c",&ans);
        int total=0;
        float moyen=0;
        for(int i=0;i<w;i++){
            total+=t[i];
        }
        moyen=(float)total/(float)w;
    if(ans=='T'){
        printf("total hours are : %d",total);
    }else if(ans=='A'){
        printf("average hours are : %f",moyen);
    }else{
        printf("enter either T or A");
    }
}








