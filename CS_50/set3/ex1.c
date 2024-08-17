#include<stdio.h>
#include<string.h>
#include<stdbool.h>
#include<ctype.h>
                        //  ex1: voting condidats
typedef struct candidas{
    char name[20];
    int count;
    bool status;
}condid;


typedef struct voters{
    char name[3][20];
}voter;

void f1_remplir(int c,char* argv[],condid* t_c);
int  f2_remplir(int c,voter* t_v,condid* t_c);
int  f1_check(char* namee,condid* t_c,voter* t_v,int c,int i,int j);                 
int  f1_vote(condid* t_c,voter* t_v,int n_v,int c);
int f2_check(condid* t_c,voter* t_v,int c,int i,int k1);
void f1_reset(condid* t_c,int c);
void f1_affichage(int c,voter* t_v,condid* t_c);

int n_v=0 ;

int main(int argc ,char* argv[]){
    if(argc<2){
        printf("usage : ./t candida1 .... \n");
        return 1;
    }
    do{
    printf("number of voters : ");
    scanf("%d",&n_v);
    getchar();
    }while(n_v<1);
    
    int c=argc-1;
    voter t_v[n_v]; condid t_c[c];
    f1_remplir(c,argv,t_c);
    f2_remplir(c,t_v,t_c);
    int win=f1_vote(t_c,t_v,n_v,c);
    f1_affichage(c,t_v,t_c);

    printf("the winner is : %s\n",t_c[win].name);
}

//add data to candidats table
void f1_remplir(int c,char* argv[],condid* t_c){
    for (int i=0,j=1;i<c;i++,j++){
        strcpy(t_c[i].name,argv[j]);
        t_c[i].count=0;
        t_c[i].status=true;
    }
}

//add data to voter table
int f2_remplir(int c,voter* t_v,condid* t_c){
    for(int i=0;i<n_v;i++){
        printf("voter number %d :\n",i+1);
        for(int j=0;j<3;j++){
            while(1){
                printf(" %d- ",j+1);
                scanf("%19[^\n]",t_v[i].name[j]);
                getchar();
                 int rs1=f1_check(t_v[i].name[j],t_c,t_v,c,i,j);
                    if(rs1==1){
                        break;
                    }
            }
        }
    }
}

//check the name that voter enter is correct
int f1_check(char* namee,condid* t_c,voter* t_v,int c,int i,int j){                 
    int t=0;
        for(int k=0;k<c;k++){
            if(!strcmp(namee,t_c[k].name)){
                t=1;
                break;
            }

        }        
            // if(j+1==c){
            //     for(int p=0;p<c;p++){
            //         if(!strcmp(t_v[i].name[p],t_v[i].name[p+1])){
            //             t=0;
            //             break;
            //         }else{t=1;};
            //     }
            // }
    return t;
}

//check the winner 
int  f1_vote(condid* t_c,voter* t_v,int n_v,int c){
    int max_id=0;
    int max=0;
    while(1){
        for(int i=0;i<n_v;i++){
            for(int j=0;j<c;j++){
                int k1=0;
                int k2=f2_check(t_c,t_v,c,i,k1); 
                if(!strcmp(t_v[i].name[k2],t_c[j].name)){
                    t_c[j].count=t_c[j].count+1;
                   if(max<t_c[j].count){
                        max= t_c[j].count;
                        max_id=j;
                    }
                break;
                }
            }
        }
        break;
    }
    if(max<((float)n_v/(float)2)){
        f1_reset(t_c,c);
        f1_vote(t_c,t_v,n_v,c);// recusiviter
    }else{  
        return max_id;
    }

} 

//check the condidat is eliminated or no
int f2_check(condid* t_c,voter* t_v,int c,int i,int k1){
    for(int h1=0;h1<c;h1++){
        if(!strcmp(t_v[i].name[k1],t_c[h1].name)){
            if(t_c[h1].status==false){
                k1=k1+1;
                f2_check(t_c,t_v,c,i,k1);
            }
        }
    }  
            return k1;
} 

// reset all the vote count to 0 than start over after elimanting 1 condidas
void f1_reset(condid* t_c,int c){
    int min=t_c[0].count;
    int min_id=0;
    for(int i=0;i<c;i++){
        if(min>=t_c[i].count){
            min=t_c[i].count;
            min_id=i;
            t_c[i].count=0;
        }
    }
    t_c[min_id].status=false;
}

//afficher resulets
void f1_affichage(int c,voter* t_v,condid* t_c){
    printf("\n check cond : \n");
    for(int i=0;i<c;i++){
            printf("\n ........................... \n");
        printf(" name : %s\n",t_c[i].name);
        printf(" count : %d \n",t_c[i].count);
        printf(" status : %d\n",(int)t_c[i].status);
            printf("\n ........................... \n");
    }
    // for(int i=0;i<n_v;i++){
    //         printf("\n ........................... \n");
    //     printf(" name 1 : %s\n",t_v[i].name[0]);
    //     printf(" name 2 : %s\n",t_v[i].name[1]);
    //     printf(" name 3 : %s\n",t_v[i].name[2]);
    //         printf("\n ........................... \n");
    // }
}


