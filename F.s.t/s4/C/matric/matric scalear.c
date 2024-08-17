#include <stdio.h>

void s_mat(int n, int m, int t[n][m])
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            printf("remplire cas t[%d][%d]", i + 1, j + 1);
            scanf("%d", &t[i][j]);
        }
    }
}
void a_mat(int n, int m, int t[n][m])
{
    printf("afficher le matrice \n ");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            printf("%d \t", t[i][j]);
        }
        printf("\n");
    }
}

void p_mat(int n, int p, int m, int a[n][p], int b[p][m], int c[n][m])
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < p; j++)
        {
            c[i][j] = 0;
            for (int k = 0; k < m; k++)
            {
                c[i][j] += a[i][k] * b[k][j];
            }
        }
    }
}

int main()
{
    int n, p, m, e, f;

    printf("donner the matrice A rows ");
    scanf("%d", &n);
    printf("donner the matrice A collumn ");
    scanf("%d", &p);
    printf("donner the matrice B collumn ");
    scanf("%d", &m);
    int a[n][p], b[p][m], c[n][m];

    s_mat(n, p, a);
    s_mat(p, m, b);

    printf("\n1: \n");

    printf("\nA \n");
    a_mat(n, p, a);
    printf("\nB \n");
    a_mat(n, p, a);

    printf("donner le scalear e :");
    scanf("%d", &f);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < p; j++)
        {
            a[i][j] = f * a[i][j];
        }
    }

    printf("\n2: \n");
    p_mat(n, p, m, a, b, c);
    a_mat(n, m, c);
}
