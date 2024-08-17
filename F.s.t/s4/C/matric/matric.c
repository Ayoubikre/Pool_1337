#include <stdio.h>

int r1, c1, r2, c2, n;

int main()
{
    do
    {
        printf("1/ donner the size of the first matrice:\n ");
        printf("\t row: ");
        scanf("%d", &r1);
        printf("\t column: ");
        scanf("%d", &c1);
        printf("2/ donner the size of the second matrice:\n ");
        printf("\t row: ");
        scanf("%d", &r2);
        printf("\t column:  ");
        scanf("%d", &c2);
        if (r2 != c1)
        {
            printf("the first row and the second collume  dosnt match , enter again. \n");
        }
    } while (r2 != c1);

    int t1[r1][c1];
    int t2[r2][c2];
    int s[r1][c2];

    printf("remplire the first matrice : \n");
    for (int i = 0; i < r1; i++)
    {
        for (int j = 0; j < c1; j++)
        {
            printf("\trow(%d) colume(%d) : ", i + 1, j + 1);
            scanf("%d", &n);
            t1[i][j] = n;
        }
    }

    printf("remplire the second matrice : \n");
    for (int i = 0; i < r2; i++)
    {
        for (int j = 0; j < c2; j++)
        {
            printf("\trow(%d) colume(%d) : ", i + 1, j + 1);
            scanf("%d", &n);
            t2[i][j] = n;
        }
    }
    /* --------------     calcul matric c      -------------- */
    for (int i = 0; i < r1; i++)
    {
        for (int j = 0; j < c2; j++)
        {
            int k = 0;
            for (int c = 0; c < r2; c++)
            {
                k += t1[i][c] * t2[c][j];
            }
            s[i][j] = k;
        }
    }

    printf("the matric c table is :\n");
    for (int i = 0; i < r1; i++)
    {
        printf("\t\t");
        for (int j = 0; j < c2; j++)
        { // c2 not r1 even tho they are equal
            printf(" %d", s[i][j]);
        }
        printf("\n");
    }

    return 0;
}