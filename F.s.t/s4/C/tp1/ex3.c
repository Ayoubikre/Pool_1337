#include<stdio.h>
#include<ctype.h>
#include<string.h>

    // Écrire un programme qui lit un entier X et un tableau tab[] entiers, et élimine toutes les occurrences de X dans tab[] en tassant les éléments restants. Utiliser 2 pointeurs pour parcourir le tableau tab[].

int main(){

    int x=0,s=5;
    int t[s];
    printf("give x : ");
    scanf("%d",&x);
    for(int i=0;i<s;i++){
        printf("give t[%d] : ",i+1);
        scanf("%d",&t[i]);
    }
    printf("..........\n");
    
    for(int i=0;i<s;i++){
        printf("t[%d] = %d\n",i+1,t[i]);
    }
    printf("..........\n");

                    //withe pionters

    for(int *p=t;p!=t+s;p++){
        int *p2;
        if(*p==x){
            for(p2=p;p2!=t+s;p2++){
                // int tmp=*p2;
                *p2=*(p2+1);
                // *(p2+1)=tmp;
            }
            p--;
            s--;
        }
    }
                    //withe no pointers

    // for(int i=0;i<s;i++){
    //     if(t[i]==x){
    //         for(int j=i+1;j<s;j++){
    //             t[j-1]=t[j];
    //         }
    //         s--;
    //         i--;
    //     }
    // }  

    printf("..........\n");

    for(int j=0;j<s;j++){
        printf("t[%d] = %d\n",j+1,t[j]);
    }


return 0;
}


