
#include <string.h>
#include <stdio.h>

int ft_strcmp(char * s1, char *s2)
{
    while (*s1 || *s2)
    {
        if(*s1 == *s2)
        {
            s1++;
            s2++;
        }
        else
            return *s1 - *s2;
    }
     return *s1 - *s2;
}

int main ()
{
    char s1[] = "amin5";
    char s2[] = "aminz";
    printf("%i\n", ft_strcmp(s1, s2));
    printf("%i\n", strcmp(s1, s2));
    
}