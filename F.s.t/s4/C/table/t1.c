#include <stdio.h>
int s;
int main()
{
    /* ------------------------------remplire table-------------------------------------------- */

    printf("donner les nombre des elemet n de table : \n");
    scanf("%d", &s);
    float t[s];
    for (int i = 0; i < s; i++)
    {
        printf(" remplire cas %d : ", i + 1);
        scanf("%f", &t[i]);
    }

    printf("the full table : \n");
    for (int i = 0; i < s; i++)
    {
        printf("| %f |", t[i]);
    }

    /* ---------------------------------oreder table ----------------------------------------- */
    float temp = 0;
    for (int i = 0; i < s; i++)
    {
        for (int j = 1; j < s - i; j++)
        {
            if (t[j - 1] > t[j])
            {
                temp = t[j - 1];
                t[j - 1] = t[j];
                t[j] = temp;
            }
        }
    }

    printf("\nthe new oorderd table : \n");
    for (int i = 0; i < s; i++)
    {
        printf("| %f |", t[i]);
    }

    /* ----------------------------------add number--------------------------------------- */
    float add;
    printf("\ndonner the number you want to add");
    scanf("%f", &add);
    s++;
    for (int i = 1; i < s; i++)
    {
        if (t[i - 1] >= add)
        {
            temp = t[i - 1];
            t[i - 1] = add;
            add = temp;
            printf("add :%f \n", add);
        }
        if (i == s - 1)
        {
            t[i] = add;
        }
    }

    printf("the new table : \n");
    for (int i = 0; i < s; i++)
    {
        printf("| %f |", t[i]);
    }

    /* --------------------------------delet number----------------------------------------- */

    float dl;
    printf("\n doner le nombre that you waant to delet : \n");
    scanf("%f", &dl);
    for (int i = 0; i < s; i++)
    {
        if (t[i] == dl)
        {
            for (int j = i; j < s; j++)
            {
                t[j] = t[j + 1];
            }
            s--;
        }
    }

    printf("the new table is : ");
    for (int i = 0; i < s; i++)
    {
        printf("| %f |", t[i]);
    }

    /* -------------------------------------------------------------------------- */
    int rst = 0;
    for (int i = 1; i < s; i++)
    {
        if (t[i] - t[i - 1] != 1 && t[i] - t[i - 1] != -1)
        {
            rst = 1;
            break;
        }
    }
    if (rst == 1)
    {
        printf("\n the table is not cosecutif \n");
    }
    else
    {
        printf("\n the table is coosucutif \n");
    }

    /* ------------------------------------revers table-------------------------------------- */
    for (int i = 0, j = s - 1 - i; i < s / 2; i++, j--)
    {
        temp = t[i];
        t[i] = t[j];
        t[j] = temp;
    }
    printf("\n");
    for (int i = 0; i < s; i++)
    {
        printf("| %f |", t[i]);
    }

    /* ----------------------------------compt inpair---------------------------------------- */
    int tst = 0;
    for (int i = 0; i < s; i++)
    {
        if (t[i] % 2 == 1)
        {
            tst++;
        }
    }
    printf("le nombre des element inpaire is : %d", tst);

    /* ------------------------------------order inpair------------------------------------- */

    int temp;
    for (int i = 0; i < s; i++)
    {
        for (int j = 1; j < s - i; j++)
        {
            if (t[j - 1] % 2 == 1)
            {
                temp = t[j - 1];
                t[j - 1] = t[j];
                t[j] = temp;
            }
        }
    }
    printf("\n");
    for (int i = 0; i < s; i++)
    {
        printf("| %f |", t[i]);
    }

    /* ------------------------------------swap to binair------------------------------------- */
    int n;
    printf("donner ue nombre : \n");
    scanf("%d", &n);

    for (int i = 7; i >= 0; i--)
    {
        t[i] = n % 2;
        n = n / 2;
    }

    for (int i = 0; i < 8; i++)
    {
        printf("| %d |", t[i]);
    }
    /* ------------------------------------count inpair------------------------------------- */

    int tst = 0;
    for (int i = 0; i < 8; i++)
    {
        if (t[i] % 2 == 1)
        {
            tst++;
        }
    }
    printf("\n le nombre des element inpaire is : %d", tst);

    return 0;
}
