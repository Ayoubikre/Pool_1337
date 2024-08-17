#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[20];
    char prename[20];
}nc;
typedef struct etud{
    int CNE;
    nc id;
    float t[3];
}node;

void ins(FILE *f1,node t[],int s);
void mod(node t[],int s);
int cmp(char*n1,char*n2,char*p1,char*p2);
void rat(node t[],int s);
char ** conv(FILE*f2,int*nb);

int main(){

    FILE *f1=fopen("ETD.txt","a");
    if(f1==NULL){
        perror("faile allocation");
        return 1;
    }

    int s=0;
    printf("give n :");
    scanf("%d",&s);
    node t[s];


    ins(f1,t,s);
    mod(t,s);
    rat(t,s);
    fclose(f1);
    FILE*f2=fopen("ETD.txt","r");
        if(f2==NULL){}
    int nb=0;
    char **t2=conv(f2,&nb);
    for(int i=0;i<nb;i++){
        printf("%s",t[i]);
    }


}
void ins(FILE *f1,node t[],int s){
    for(int i=0;i<s;i++){
        printf("cne : ");
        scanf("%d",&t[i].CNE);
        getchar();

        printf("name : ");
        scanf("%19[^\n]",t[i].id.name);
        getchar();

        printf("prename : ");
        scanf("%19[^\n]",t[i].id.prename);
        getchar();

        printf("note tp : ");
        scanf("%f",&t[i].t[0]);
        getchar();

        printf("note cf : ");
        scanf("%f",&t[i].t[1]);
        getchar();

        t[i].t[2]=(0.2*t[i].t[0])+(0.8*t[i].t[1]);

        fprintf(f1,"%s - %s\n",t[i].id.name,t[i].id.prename);
        printf("\n");
    }
}

void mod(node t[],int s){
    char ans;
    printf("do you want to change note of a student yes or no :  ");
    scanf("%c",&ans);
    getchar();
    
    if(ans!='y'&&ans!='Y'){
        return;
    }else{
        char name[20];
        char prename[20];
        printf("give name : ");
        scanf("%19[^\n]",name);

        printf("give prename : ");
        scanf(" %19[^\n]",prename);
        for(int i=0 ;i<s;i++){
            if( cmp(t[i].id.name , name , t[i].id.prename , prename)==0 ){
                printf("give the new note value : ");
                scanf("%f",&t[i].t[1]);

                t[i].t[2]=(0.2*t[i].t[0])+(0.8*t[i].t[1]);
            }
        }
    }
}   
int cmp(char*n1,char*n2,char*p1,char*p2){
    while(*n1&&(*n1==*n2)){
        n1++;n2++;
    }
    printf("%d\n",*n1-*n2);

    while(*p1&&(*p1==*p2)){
        p1++;p2++;
    }
    printf("%d\n",*p1-*p2);

    return (*n1-*n2)+(*p1-*p2);
}
void rat(node t[],int s){
    printf("\nlist rattrapage : \n");
    for(int i=0;i<s;i++){
        if(t[i].t[2]<10){
            printf(" %d : %s %s\n",i+1,t[i].id.name,t[i].id.prename);
        }
    }
}
char ** conv(FILE*f2,int*nb){
    int s=10;
    char *(*t2)=malloc(s*sizeof(char));
        if(*t2==NULL){
            perror("failed 1");
            return NULL;
        }
    char buffer[50];
    while(fscanf(f2,"%49[^\n]",buffer)==1){
        t2[*nb]=malloc(40*sizeof(char));
            if(t2[*nb]==NULL){
                perror("failed 2");
                return NULL;
            }
        strcpy(t2[*nb],buffer);
        if(*nb>=s){
           s=s*2;
          t2=realloc(t2,s*sizeof(char));    
        }
        *nb=*nb+1;
    }
return t2;
}
