#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

// hash the inpute by a certain number forward

int main(int argc ,char *argv[]){
    if(argc !=2 ){
        printf("usage : ./t key\n");
    }
    else{
        for(int i=0;i<argv[1][i];i++){
            if(isalpha(argv[1][i])){
                printf("the key should only contain numbers\n"); // get inpute
                return 1;
            }
        }
        int k=(atoi(argv[1]))%26;
        // printf("%d\n",k);
        if(k<0){
            k=k+26;
        }
        char ch1[50];
        char ch2[50];

        printf("plain text : ");
        scanf("%49[^\n]",ch1);
        getchar();

        //hash the inpute 

        int s=strlen(ch1);
        for(int i=0;i<s;i++){
            if(isalpha(ch1[i])){
                int n1 =ch1[i];
                n1=n1+k;
                    if(n1<123){
                        char n2 =n1;
                        ch2[i]=n2;
                    }else{
                        n1=(n1-122)+96;
                        char n2 =n1;
                        ch2[i]=n2; 
                    }
            }
            else{
                ch2[i]=ch1[i];
            }
        }
        printf("hash text : ");
        for(int i=0;i<s;i++){
            printf("%c",ch2[i]);
        }
        printf("\n");   
    }

return 0;
}