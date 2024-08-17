#include<stdio.h>
#include<stdlib.h>

void verifier(int *t1,int  n1);
int inclusion(int *t1,int  n1,int *t2,int  n2);
int * fusion(int *t1,int n1,int *t2,int n2);

int main(){
    int n1=0;
    printf("give N : ");
    scanf("%d",&n1);

    int *t1=malloc(n1*sizeof(int));
    for(int i=0;i<n1;i++){
        printf("T1[%d]: ",i+1);
        scanf("%d",&t1[i]);
    }
    verifier(t1,n1);


    int n2=2;
    int *t2=malloc(n2*sizeof(int));
        for(int i=0;i<n2;i++){
            printf("T2[%d]: ",i+1);
            scanf("%d",&t2[i]);
        }
    int rs2=inclusion(t1,n1,t2,n2);
        if(rs2==0){
            printf("all the elemet are included\n");
        }else{
            printf("not all the elemtents are included\n");
        }


    int n3=n1+n2;
    int *t3=fusion(t1,n1,t2,n2);
        for(int i=0;i<n3;i++){
            printf("T3[%d]: %d \n",i+1,t3[i]);
        }

    free(t1);
    free(t2);
    free(t3);
 return 0;
}

void verifier(int *t1,int  n1){
    int check =0;
    for(int i=0;i<n1;i++){
        if(t1[i]>0){
            for(int j=i+1;j<n1;j++){
                if(t1[i]==t1[j]){
                    check =1;
                }
            }            
        }else{
            check =1;
        }
    }
    if(check!= 0){
        printf("the table is not ensembe de taile N\n");
    }else{
        printf("the table is ensemble de taile de N\n");
    }
}

int inclusion(int *t1,int  n1,int *t2,int n2){
    int count=0;
    for(int i=0;i<n2;i++){
        for(int j=0;j<n1;j++){
            if(t2[i]==t1[j]){
                count+=1;
                break;
            }
        }
    }
    if(count==n2){
        return 0;
    }else{
        return 1;
    }
}

int *fusion(int *t1,int n1,int *t2,int n2){
    int *t=malloc((n1+n2)*sizeof(int));
    for(int i=0;i<n1;i++){
        t[i]=t1[i];
    }
    for(int i=0,j=n1;i<n2;i++,j++){
        t[j]=t2[i];
    }
    
    return t;
}


