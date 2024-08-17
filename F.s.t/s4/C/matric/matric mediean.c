#include <stdio.h>

void smat(int n, int m, int t[n][m])
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            printf("saiser t[%d][%d] :", i + 1, j + 1);
            scanf("%d", &t[i][j]);
        }
    }
}

void amat(int n, int m, int t[n][m])
{
    printf("the full matric : \n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            printf(" %d \t", t[i][j]);
        }
        printf("\n");
    }
}
void med(int n, int m, int t[n][m])
{
    int k = n * m;
    int R[k];
    int c = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            R[c] = t[i][j];
            c++;
        }
    }
    printf("\n");

    for (int i = 0; i < k; i++)
    {
        printf("%d \t", R[i]);
    }
    printf("\n");

    int temp;
    for (int i = 0; i < k; i++)
    {
        for (int j = 1; j < k - i; j++)
        {
            if (R[j - 1] > R[j])
            {
                temp = R[j - 1];
                R[j - 1] = R[j];
                R[j] = temp;
            }
        }
    }
    printf("\n");
    for (int i = 0; i < k; i++)
    {
        printf("%d \t", R[i]);
    }
    printf("\n");
    int med;
    med = R[k / 2];
    printf("le valeur med is :%d", med);
}


int main(){
    int n, m;

    printf("give matrice A row size \n");
    scanf("%d", &n);
    printf("give matrice A collumn siz \n");
    scanf("%d", &m);
    int A[n][m];
    smat(n, m, A);
    amat(n, m, A);
    med(n, m, A);
}

