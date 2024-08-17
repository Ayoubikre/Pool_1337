#include <stdio.h>
int main()
{
    int s;
    printf("donner the size of the table : \n");
    scanf("%d", &s);

    int t[s];
    for (int i = 0; i < s; i++)
    {
        printf("insert number %d : \n", i + 1);
        scanf("%d", &t[i]);
    }

    printf("the table :\n");
    for (int i = 0; i < s; i++)
    {
        printf("| %d |", t[i]);
    }

    int temp1 = 0;
    for (int i = 0; i < s; i++)
    {
        for (int j = 1; j < s; j++)
        {
            if (t[j - 1] > t[j])
            {
                temp1 = t[j - 1];
                t[j - 1] = t[j];
                t[j] = temp1;
            }
        }
    }
    printf("\n the table on order : \n");
    for (int i = 0; i < s; i++)
    {
        printf("| %d |", t[i]);
    }

    int del, temp2 = 0, test = 0;
    printf("\n donnet le value that you want to del from the table :\n");
    scanf("%d", &del);
    for (int i = 0; i < s; i++)
    {
        if (del == t[i])
        {
            for (int j = i + 1; j < s; j++)
            {
                temp2 = t[j - 1];
                t[j - 1] = t[j];
                t[j] = temp2;
            }
            test = 1;
        }
    }
    if (test == 1)
    {
        s--;
    }
    printf("the new table after the delet number :\n");
    for (int i = 0; i < s; i++)
    {
        printf("| %d |", t[i]);
    }

    int r = 1;
    for (int i = 1; i < s; i++)
    {
        if (t[i - 1] - t[i] != 1 && t[i - 1] - t[i] != -1)
        {
            r = 0;
        }
    }
    if (r == 1)
    {
        printf("\n the table is consecutif \n");
    }
    else
    {
        printf("\n the tale is NOT consecutif \n");
    }
}