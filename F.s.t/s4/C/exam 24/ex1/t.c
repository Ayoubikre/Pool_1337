#include <stdio.h>
#include <stdlib.h>
#include <string.h>

                // ****** ex1 of 2024 exam normal ********

char ** tmc(FILE*f1 ,FILE *f2 ,int *nb);

int main(int argc ,char **argv){
    if(argc!=3){
        printf("cnd : ./t file1 file 2");
        return 1;
    }else{
        FILE *f1=fopen(argv[1],"r");
            if(f1==NULL){
                perror("file 1");
                return 1;
            }
        FILE *f2=fopen(argv[2],"r");
            if(f2==NULL){
                perror("file 2");
                return 1;
            }

        int nb=0;

        char **t = tmc(f1,f2,&nb);
            if(t==NULL){
                printf("ther no match between the 2 files .");
                return 0;
            }else{
                printf("there is %d match between the 2 files :\n",nb);
                int i=0;
                    while(i<nb){
                        printf("\t%s",t[i]);
                        free(t[i]);
                        i++;
                    }
            }
        
        fclose(f1);
        fclose(f2);
        free(t);

    return 0;
    }
}

char ** tmc(FILE*f1 ,FILE *f2 ,int *nb){

    int max=50;
    char ** t=malloc(max*sizeof(char*));
        if(t==NULL){
            perror("error");
        }

    char b1[50],b2[50];
    while(fgets(b1,sizeof(b1),f1)!=NULL){
        while(fgets(b2,sizeof(b2),f2)!=NULL){
            if(!strcmp(b1,b2)){
                    if(*nb>=max){
                        max=max+50;
                        t=realloc(t,max*sizeof(char));
                    }
                int s=strlen(b1);
                t[*nb]=malloc(s*sizeof(char));
                strcpy(t[*nb],b1);
                *nb=*nb+1; 
                break; 
            }
        }
    }

return t;
}
