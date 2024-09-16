/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Noctis <Noctis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 06:37:49 by Noctis            #+#    #+#             */
/*   Updated: 2024/09/16 05:46:36 by Noctis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int		ft_calc(char *t, char *sp);
char	*ft_calc2(char *t, char *sp, int s, int *f);
char	*ft_cpy(char *str, int s2);
char	*ft_fix(char *str, char *sp, int s1, int *s2);

char	**ft_split(char *str, char *charset)
{
	int		i;
	int		j;
	int		s1;
	int		s2;
	char	**t;

	i = 0;
	j = 0;
	s1 = ft_calc(str, charset);
	// printf("%d\n",s1);
	t = malloc(s1 * sizeof(char *));
	while (i < s1 - 1)
	{
		str = ft_fix(str, charset, s1, &s2);
		t[i] = ft_cpy(str, s2);
		str += s2+1;
		i++;
	}
	t[i] = NULL;
	return (t);
}
char	*ft_fix(char *t, char *sp, int s1, int *s2)
{
	int	s;
	int	i;
    int j;

	s = 0;
	while (sp[s])
		s++;
		i = 0;
	while (t[i])
	{
        		// printf("Substring ");
            j=0;
		if (t[0] == sp[j])
		{
			while (sp[j] ==t[j])
				j++;
			if (j == s)
				t = t + s;
		}
		else
		{
			if (t[i] != sp[j])
				(*s2)++;
			else
			{
				while (sp[j] == t[i])
					j++;
				if (j == s)
					break ;
			}
		}
        i++;
	}
    	printf("i = | %d |\n",i);
    	printf("j = | %d |\n",j);
    	printf("* %d *\n",*s2);

	return (t);
}

char	*ft_cpy(char *str, int s)
{
	int		i;
	char	*t;

	i = 0;
	t = malloc((s + 1) * sizeof(char));
	while (i < s)
	{
		t[i] = str[i];
		i++;
	}
	t[i] = '\0';
	return (t);
}

int	ft_calc(char *t, char *sp)
{
	int	f;
	int	count;
	int	s;

	s = 0;
	f = 0;
	count = 0;
	while (sp[s])
		s++;
	while (*t)
	{
		if (*t != sp[0])
		{
			if (f == 0)
			{
				f = 1;
				count++;
			}
			t++;
		}
		else
			t = ft_calc2(t, sp, s, &f);
	}
	return (++count);
}

char	*ft_calc2(char *t, char *sp, int s, int *f)
{
	int	i;

	i = 0;
	while (sp[i])
	{
		if (*(t + i) == sp[i])
			i++;
	}
	if (s == i)
	{
		*f = 0;
		t = t + i;
	}
	return (t);
}

int	main(void)
{
	char	str[] = "hello__this__is__a__test";
	char	charset[] = "__";
	char	**result;
	int		i;

	result = ft_split(str, charset);
	i = 0;
	while (result[i] != NULL)
	{
		printf("Substring %d: %s\n", i + 1, result[i]);
		i++;
	}
	i = 0;
	while (result[i] != NULL)
	{
		free(result[i]);
		i++;
	}
	free(result);
	return (0);
}
