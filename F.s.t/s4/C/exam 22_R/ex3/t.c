#include<stdio.h>
#include<stdlib.h>

typedef struct edition{
    char nom_ed[50];
    int anner;
}edition;

typedef struct livre{
    int code;
    char titre[100];
    char nom_au[50];
    edition node;
}livre;

livre *creat(int n);

int main(){
    int n;
    printf("donner n : ");
    scanf("%d",&n);
    livre *t1=creat(n);
}

livre *creat(int n){
    livre *t=malloc(n*sizeof(livre));
    for(int i=0;i<n;i++){
        printf("\n\tlivre %d ................\n",i+1);

        printf("code : ");
        scanf("%d",&t[i].code);
        getchar();

        printf("titre : ");
        scanf("%49[^\n]",t[i].titre);
        getchar();

        printf("nom_author : ");
        scanf("%49[^\n]",t[i].nom_au);
        getchar();

        printf("edition : ");
        scanf("%49[^\n]",t[i].node.nom_ed);
        getchar();

        printf("anner : ");
        scanf("%d",&t[i].node.anner);
        getchar();
    }
return t;
}
void listing(livre *t,int n){
    for(int i=0;i<n;i++){
        for(int j=1;j<n-i;j++){
            if(t[j-1].code>t[j].code){
                livre tmp=t[j-1];
                t[j-1]=t[j];
                t[j]=tmp;
            }
        }
    }
    for(int i=0;i<n;i++){
        printf("\n\tlivre %d ................\n",i+1);
        printf("code : %d \n",t[i].code);
        printf("titre : %s \n",t[i].titre);
        printf("nom_author : %s \n",t[i].nom_au);
        printf("edition : %s \n",t[i].node.nom_ed);
        printf("anner : %d \n",t[i].node.anner);
    }
}

void search(livre *t,int n){
    char buffer[50];
    printf("search for title :");
    scanf("%49[^\n]",buffer);

    int s=0;
    for(int i=0;buffer[i]!='\0';i++){
        s=s+1;
    }

    for(int i=0;i<n;i++){
        int rs=1;

        for(int j=0;j<s;j++){
            if(buffer[j]!=t[i].titre[j]){
                rs=0;
            }
        }

        if(rs!=1){
            continue;
        }else{
            printf("code : %d \n",t[i].code);
            printf("titre : %s \n",t[i].titre);
            printf("nom_author : %s \n",t[i].nom_au);
            printf("edition : %s \n",t[i].node.nom_ed);
            printf("anner : %d \n",t[i].node.anner);
            break;
        }
        
    }
}

void delet(livre *t,int *n){
    for(int i=0;i<*n;i++){
        if(t[i].node.anner<1990){
            t[i]=t[*n-1];
            *n=*n-1;
            i--;
        }
    }
    listing(t,*n);
}

void save(livre *t,int n){
    FILE *f1=fopen("bib.txt","a");
        if(f1==NULL){
            printf("error");
            perror;
        }
    for(int i=0;i<n;i++){
        fprintf(f1,"\n\tlive %d\n",i+1);
        fprintf(f1,"code : %d \n",t[i].code);
        fprintf(f1,"titre : %s \n",t[i].titre);
        fprintf(f1,"nom_author : %s \n",t[i].nom_au);
        fprintf(f1,"edition : %s \n",t[i].node.nom_ed);
        fprintf(f1,"anner : %d \n",t[i].node.anner);
    }
    fclose(f1);
}