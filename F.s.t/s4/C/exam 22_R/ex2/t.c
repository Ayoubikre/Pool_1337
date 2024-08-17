#include<stdio.h>

int main(){
    int n,m,p;
    printf("dooner les dimension de matric A et B\n");
    printf("n : ");
    scanf("%d",&n);
    printf("m : ");
    scanf("%d",&m);
    printf("p : ");
    scanf("%d",&p);

    int a[n][m];
    printf("remplire le matric A :\n");
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            printf("A[%d][%d]",i+1,j+1);
            scanf("%d",&a[i][j]);
        }
    }

    int b[n][m];
    printf("remplire le matric B :\n");
    for(int i=0;i<m;i++){
        for(int j=0;j<p;j++){
            printf("B[%d][%d]",i+1,j+1);
            scanf("%d",&b[i][j]);
        }
    }

    int c[n][p];
    for(int i=0;i<n;i++){
        for(int j=0;j<p;j++){
            int k=0;
            for(int f=0;f<m;f++){
                k+=a[i][f]*b[f][j];
            }
            c[i][j]=k;
        }
    }

    printf("results :\n");
    for(int i=0;i<n;i++){
        for(int j=0;j<p;j++){
            printf("| %d |",c[i][j]);
        }
        printf("\n");
    }
}

