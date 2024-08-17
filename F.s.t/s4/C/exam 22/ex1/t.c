#include <stdio.h>
#include <stdlib.h>

char* compres(char *t1);
int * ocur (char *t1,char*t2,int s);
char* decomp(char *t2,int *t3,int s);

int main(){
    char t1[100];
    printf("give a sentence : ");

            //  %s      :   read till whitespace 
            //  %[^\n]  :   read till next line

    scanf("%99[^\n]",t1);
    getchar();

    char *t2=compres(t1);
    printf("compresion of \" %s \" : %s\n",t1,t2);

    int s=0;
    for(int i=0;t2[i]!='\0';i++){
        s=s+1;
    }
    
    int *t3=ocur(t1,t2,s);

    char*t4=decomp(t2,t3,s);
    printf("decompresion of \" %s \" : %s\n",t2,t4);


    free(t2);
    free(t3);
    free(t4);
return 0;
}

char* compres(char *t1){
    int nb=0;
    char*t2=malloc(100*sizeof(char));
        if(t2==NULL){
            perror("failed");
            return NULL;
        }

    for(int i=0;t1[i]!='\0';i++){
        if(t1[i]-t1[i-1]!=0){
            t2[nb]=t1[i];
            nb=nb+1;
        }
    }

return t2;
}


int * ocur(char *t1,char*t2,int s){
    int nb=0,count=1;
    int *t3=malloc(s*sizeof(int));
        if(t3==NULL){
            perror("failed");
            return NULL;
        }

    for(int i=0;t1[i]!='\0';i++){
        if(t1[i]-t1[i+1]==0){
            count=count+1;
        }else{
            t3[nb]=count;
            nb=nb+1;
            count=1;
        }
    }

return t3;
}


char* decomp(char *t2,int *t3,int s){
    int x=0;
    for(int i=0;i<s;i++){
        x=x+t3[i];
    }

    char*t4=malloc(x*sizeof(char));
        if(t4==NULL){
            perror("failed");
            return NULL;
        }

    int nb=0;
    for(int i=0;i<s;i++){
        for(int j=0;j<t3[i];j++){
            t4[nb]=t2[i];
            nb=nb+1;
        }
    }

return t4;
}
