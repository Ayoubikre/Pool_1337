#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char **rech(FILE *f1,char letter , int *nb);

int main(){

    FILE* f1=fopen("t1.txt","r");
        if(f1==NULL){
            perror("faile to allocaed memroy");
            return 1;
        }

    char letter;
    printf("give a letter to search for : ");
    scanf(" %c",&letter);

    int nb=0;
    char ** t=rech(f1,letter,&nb);

    if(t==NULL){
        printf("\nther is %d match that stared with the : %c\n",nb,letter);
    }else{
        printf("\nther is %d match that stared with the : %c\n",nb,letter);

        for(int i=0;i<nb;i++){
            printf("%s",t[i]);
            free(t[i]);
        }
    }

    fclose(f1);
    free(t);
    return 0;
}
char **rech(FILE *f1,char letter , int *nb){

    char buffer[100];
    int s2=20;
    char*(*t)=malloc(s2*sizeof(char));

    while(fgets(buffer, sizeof(buffer), f1)!=NULL){
        if(buffer[0]==letter){
            
            int s=strlen(buffer);
            t[*nb]=malloc(s*sizeof(char));
                if(t[*nb]==NULL){
                    perror("faild to allocate ");
                    return NULL;
                }
            strcpy(t[*nb],buffer);

            *nb=*nb+1;
                if(*nb>s2){
                    s2=s2*2;
                    t=realloc(t,s2*sizeof(char));
                }
        }
    }

    if(*nb>0){
        return t;
    }else{
        return NULL;
    }
}
