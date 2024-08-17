#include<stdio.h>
#include<stdlib.h>

int main(){
    int n=0;
    printf("donner N : ");
    scanf("%d",&n);

    int t[n+1][n+1];
    for(int i=0;i<n+1;i++){
        for(int j=0;j<n+1;j++){
            t[i][j]=0;
            if(j==0){t[i][j]=1;}
        }
    }

    for(int i=1;i<n+1;i++){
        for(int j=1;j<n+1;j++){
            t[i][j]=t[i-1][j-1]+t[i-1][j];
            // printf("| %d |",t[i][j]);
        }
    }

        int c=0;
    for(int i=0;i<n+1;i++){
        for(int j=0;j<=c;j++){
            printf(" %d ",t[i][j]);
        }
        printf("\n");
        c++;
    }
    



    return 0;
}