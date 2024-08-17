#include <stdio.h>

int coder(int n, char *nom_f1 ,char*nom_f2);

int main(){
    int n=0;
    printf("give une n de deplacment : ");
    scanf("%d",&n);
    getchar();

    char nom_f1[50];
    printf("give le nom de fichie 1 : ");
    scanf("%49[^\n]",nom_f1);
    getchar();

    char nom_f2[50];
    printf("give le nom de fichie 2 : ");
    scanf("%49[^\n]",nom_f2);
    getchar();

    coder(n,nom_f1,nom_f2);


return 0;
}
int coder(int n, char *nom_f1 ,char*nom_f2){
    FILE *f1=fopen(nom_f1,"r");
    if(f1==NULL){
        printf("error");
        return 1;
    }

    FILE *f2=fopen(nom_f2,"a");
        if(f2==NULL){
            printf("error");
            return 1;
        }
    char rs;
    while(fscanf(f1,"%c",&rs)==1){
        if(rs!='c'){
            fprintf(f2,"%c",rs);
        }else{
            rs=('c'+n)%256;
            fprintf(f2,"%c",rs);
            
        }

    }
    fclose(f1);
    fclose(f2);

}