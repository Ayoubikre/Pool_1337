#include <stdio.h>
#include <string.h>
int main()
{
    /* -------------------------------------------------------------------------- */
    /*                                      1                                     */
    /* -------------------------------------------------------------------------- */

    char t[100];
    int s, r1 = 0, wc = 0;

    printf("donne une sentence : ");
    scanf("%[^\n]", t);
    s = strlen(t);
    for (int i = 0; i <= s; i++)
    {
        if (t[i] != ' ' && t[i] != '\0')
        {
            r1++;
        }
        else if (r1 > 0)
        {
            wc++;
            r1 = 0;
        }
    }
    printf("word count is : %d", wc);

    /* -------------------------------------------------------------------------- */
    /*                                      2                                    */
    /* -------------------------------------------------------------------------- */

    int cc = 0;
    char r2;
    printf("\n donne une charecter : ");
    scanf(" %c", &r2);
    for (int i = 0; i < s; i++)
    {
        if (t[i] == r2)
        {
            cc++;
        }
    }
    printf("\n the number of accurence de %c is : %d ", r2, cc);
    /* -------------------------------------------------------------------------- */
    /*                                      3                                     */
    /* -------------------------------------------------------------------------- */

    char temp;
    for (int i = 0; i < s; i++)
    {
        if (t[0] == ' ' || (t[i] == ' ' && t[i - 1] == ' '))
        {
            for (int j = i + 1; j < s; j++)
            {
                temp = t[j - 1];
                t[j - 1] = t[j];
                t[j] = temp;
            }
            t[s - 1] = '\0';
            i--;
        }
    }
    printf("\n the new sentence is : \n");
    printf("%s", t);
    /* -------------------------------------------------------------------------- */
    /*                                      4                                     */
    /* -------------------------------------------------------------------------- */

    s = strlen(t);

    for (int i = 0; i <= s / 2; i++)
    {
        for (int j = s - 1 - i; j >= s / 2; j--)
        {
            temp = t[i];
            t[i] = t[j];
            t[j] = temp;
            break;
        }
    }
    printf("\n the new sentece is : \n");
    printf("%s", t);
    /* -------------------------------------------------------------------------- */
    /*                                      5                                     */
    /* -------------------------------------------------------------------------- */

    char b[50];
    int s2, r3 = 1;
    printf("\n dooner le chain que vous vouler supprimer : \n");
    scanf(" %[^\n]", b);
    s2 = strlen(b);
    for (int i = 0; i < s2; i++)
    {
        if (t[i] != b[i])
        {
            r3 = 0;
        }
    }
    if (r3 == 0)
    {
        printf("dont match");
    }
    else
    {
        for (int i = 0; i < s2; i++)
        {
            for (int j = 1; j < s; j++)
            {
                temp = t[j - 1];
                t[j - 1] = t[j];
                t[j] = temp;
            }
            t[s - 1] = '\0';
        }
        printf("\n %s \n", t);
    }
}