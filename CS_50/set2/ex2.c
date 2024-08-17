#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdbool.h>

//hash the inpute by a key with a 26 char

char ch[26];
char ch1[50];
char ch2[50];
int main(int argc, char *argv[]){

    if (argc != 2 || strlen(argv[1])!=26 ){
        printf("usage : ./t key \"26 char\"  ");
        return 1;
    }
    for(int i=0;i<26;i++){
        if(!isalpha(argv[1][i])){
            printf("only chr is allowd");
            return 1;
        }
        else{
            ch[i]=argv[1][i];
        }
    }

    printf("plain text : ");
    scanf("%49[^\n]",ch1);
    getchar();

    int s=strlen(ch1);
    int t1=0;
    for(int i=0;i<s;i++){
        if(!isalpha(ch1[i])){
            ch2[i]=ch1[i];
        }else{
        t1=ch1[i];
        int k=t1-96;
        ch2[i]=ch[k-1];
        }
    }
    printf("hash text : ");
    for(int i=0; i<s;i++){
        printf("%c",ch2[i]);
    }
    printf("\n");
return 0; 

}