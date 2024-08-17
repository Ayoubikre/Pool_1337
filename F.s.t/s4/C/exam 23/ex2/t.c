#include<stdio.h>
#include<stdlib.h>


void fus(char*f_1,char*f_2,char*f_3);

int main(){
    // char f_1[20];
    // char f_2[20];
    // char f_3[20];
    // printf("give the file 1 name : ");
    // scanf("%s",f_1);
    // printf("give the file 2 name : ");
    // scanf("%s",f_2);
    // printf("give the file 3 name : ");
    // scanf("%s",f_3);

    char* f_1="t1.txt";
    char* f_2="t2.txt";
    char* f_3="t3.txt";
   
    fus(f_1,f_2,f_3);

return 0;
}


void fus(char*f_1,char*f_2,char*f_3){

                                        // open file
    FILE *f1=fopen(f_1,"r");
        if(f1==NULL){
            printf("cant open file 1");
            return;
        }
    FILE *f2=fopen(f_2,"r");
        if(f2==NULL){
            printf("cant open file 2");
            return;
        }

    FILE *f3=fopen(f_3,"w");
        if(f3==NULL){
            printf("cant creat file 3");
            return;
        }
            printf("pass\n");




    int *t=malloc(100*sizeof(int));
    int count=0;
    int size=100;

                                            //scanf f1 data to a table
    while(fscanf(f1,"%d",&t[count])==1){
        count++;
        if(count>=size){
            size=size*2;
            t=realloc(t,size*sizeof(int));
            if(t==NULL){
                printf("error f2");
                fclose(f1);
            }
        }
    }
                                        //scanf fw data to the same  table

    while(fscanf(f2,"%d",&t[count])==1){
        count++;
        if(count>=size){
            size=size*2;
            t=realloc(t,size*sizeof(int));
            if(t==NULL){
                printf("error f2");
                fclose(f1);
                fclose(f2);
            }
        }
    }

                                    // sort
    for(int i=0;i<count;i++){
        for(int j=1;j<count-i;j++){
            if(t[j]<t[j-1]){
                int tmp=t[j-1];
                t[j-1]=t[j];
                t[j]=tmp;
            }
        }
    }
                                // print in consol
    for(int i=0;i<count;i++){
        printf("%d\n",t[i]);
    }
                                // print in f3
    for(int i=0;i<count;i++){
        fprintf(f3,"%d\n",t[i]);
    }

                                // close
    fclose(f1);
    fclose(f2);
    fclose(f3);
    free(t);
    
}

