#include <stdio.h>
#include <string.h>
int main()
{
    char t[100];
    printf("donenr une chain de carachtere : ");
    scanf("%[^\n]", t);
    printf("%s", t);
    int s;
    s = strlen(t);
    printf("s: %d ", s);

    char temp;
    for (int i = 0; i < s; i++)
    {
        int test = 0;
        if (t[i] == ' ')
        {

            for (int j = i + 1; j < s; j++)
            {
                temp = t[j - 1];
                t[j - 1] = t[j];
                t[j] = temp;
                // printf("%s \n", t);
            }

            t[s - 1] = '\0';
            i--;
        }
    }

    printf("\n the new sntense is : %s \n", t);

    int c = 0, r = 0;
    for (int i = 0; i <= s; i++)
    {
        if (t[i] != ' ' && t[i] != '\0')
        {
            c++;
            printf(" %d\n", c);
        }
        else if (c > 8)
        {
            r++;
            c = 0;
        }
        else
        {
            c = 0;
        }
    }
    printf("rsultas : %d", r);
}
