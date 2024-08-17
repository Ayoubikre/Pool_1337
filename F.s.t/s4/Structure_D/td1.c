#include<stdio.h>
#include<string.h>


typedef struct date{
    int jour;
    int mois;
    int an;
}date;
typedef struct etu{
    char nom[20];
    char cne[20];
    date date_ns;
    char fl[20];
    int s;
    float t[6];
    
}etu;
etu t[3];

void saisie(){
    for (int i=0;i<3;i++){
    printf("........etudient [%d]\n",i+1);

        printf("\ngive name : ");
        scanf("%[^\n]s",t[i].nom);
        getchar();

        printf("\ngive cne : ");
        scanf("%[^\n]s",t[i].cne);
        getchar();

        printf("\ngive birth date 'j' : ");
        scanf("%d",&t[i].date_ns.jour);
        printf("\ngive birth date 'm' : ");
        scanf("%d",&t[i].date_ns.mois);
        printf("\ngive birth date 'a' : ");
        scanf("%d",&t[i].date_ns.an);
        getchar();

        printf("\ngive filier : ");
        scanf("%[^\n]s",t[i].fl);
        getchar();

        printf("\ngive semseter : ");
        scanf("%d",&t[i].s);
        getchar();

        for(int j=0;j<6;j++){
            printf("\ngive note [%d] : ",j+1);
            scanf("%f",&t[i].t[j]);
        }
        getchar();
    }
}


etu t_sma[3];
etu t_smi[3];
void par_f(){
    int k1=0,k2=0;
    for(int i=0;i<3;i++){
        if(!strcmp(t[i].fl,"smi")){
            if(k1>=3){
                printf("no more place");
                return;
            }
            t_smi[k1]=t[i];
            k1=k1+1;
        }
        else if(!strcmp(t[i].fl,"sma")){
            if(k2>=3){
                printf("no more place");
                return;
            }
            t_sma[k1]=t[i];
            k2=k2+1;
        }else{
            continue;
        }
    }
}

etu t_s4[3];
void par_s(){
    int k1=0;
    for(int i=0;i<3;i++){
        if(t[i].s==4 && ( !strcmp(t[i].fl,"smi") || !strcmp(t[i].fl,"smi") )){
            if(k1>=3){
                printf("no more place");
                return;
            }
            t_s4[k1]=t[i];
            k1++;
        }else{
            continue;
        }
    }
}

void afichage(){
    for(int i=0;i<3;i++){
        printf("\n nome : %s",t_s4[i].nom);
        printf("  note : %f\n",t_s4[i].t[1]);
    }
}
int valider(){
    int count=0;
    for(int i=0;i<3;i++){
        if(t_s4[i].t[1]>=10.00){
            count++;
        }else{
            continue;
        }
    }
    return count;
}
int main(){
    saisie();
    par_f();
    par_s();
    afichage();
    int v=valider();
    printf("nombere de validation de modul s.d is : %d",v);

return 0;
}
