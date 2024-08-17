#include <stdio.h>
#include <string.h>

int s;
char t[50], temp;

int main()
{
    /* -------------------------------------------------------------------------- */
    /*                   get the sentence and count the longeur                   */
    /* -------------------------------------------------------------------------- */
    printf("give a sentense : ");
    scanf("%[^\n]", t);
    s = strlen(t);
    printf(" le loneure is : %d \n", s);
    printf("%s x\n", t);

    /* -------------------------------------------------------------------------- */
    /*                       eliminate all the space between                      */
    /* -------------------------------------------------------------------------- */

    // for (int i = 0; i < s; i++)
    // {
    //     int test = 0;
    //     if (t[i] == ' ')
    //     {

    //         for (int j = i + 1; j < s; j++)
    //         {
    //             temp = t[j - 1];
    //             t[j - 1] = t[j];
    //             t[j] = temp;
    //             printf("%s \n", t);
    //         }

    //         t[s - 1] = '\0';
    //         i--;
    //     }
    // }
    // printf("\n the new sntense is : %s \n", t);

    /* -------------------------------------------------------------------------- */
    /*                      calcul les nombere mons de 7 char                     */
    /* -------------------------------------------------------------------------- */
    int w_count = 0, l_count = 0;
    for (int i = 0; i <= s; i++)
    {
        if (t[i] != ' ' && t[i] != '\0')
        {
            l_count++;
        }
        else if (l_count > 7)
        {
            w_count++;
            l_count = 0;
        }
        else
        {
            l_count = 0;
        }
    }

    printf("the number of word that have more than 7 char is : %d", w_count);
}
