#include<stdio.h>
#include<ctype.h>
#include<string.h>

// Écrire un programme qui range les éléments d’un tableau d’entiers tab[] dans l’ordre inverse. Utiliser 2 pointeurs et une variable de permutation.



int main(){
    int x=0,s=5;
    int t[s];
    for(int i=0;i<s;i++){
        printf("give t[%d] : ",i+1);
        scanf("%d",&t[i]);
    }

                printf("..........\n");
    
    for(int i=0;i<s;i++){
        printf("t[%d] = %d\n",i+1,t[i]);
    }

                printf("..........\n");
                
    // int *p1=t;
    // int *p2=p1+1;
    // while(p1!=t+s-1){
    //             printf(":: %d\n",*p1);
    //             printf(".. %d\n",*p2);
    //     if(*p1<*p2){
    //         int tmp=*p1;
    //         *p1=*p2;
    //         *p2=tmp;

    //         p1=t;
    //         p2=p1+1;
    //     }else{
    //     p1++;
    //     p2++;
    //     }
    // }    

    for(int *p1=t;p1!=t+s-1;p1++){
        int *p2=p1+1;
            if(*p1<*p2){
                int tmp=*p1;
                *p1=*p2;
                *p2=tmp;
                p1=t-1;  //imp
            }
    }


                printf("pass\n..........\n");
    
    for(int i=0;i<s;i++){
        printf("t[%d] = %d\n",i+1,t[i]);
    }











return 0;
}
