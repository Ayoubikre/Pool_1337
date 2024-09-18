/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Noctis <Noctis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 12:44:22 by Noctis            #+#    #+#             */
/*   Updated: 2024/09/18 15:59:40 by Noctis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

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

int	ft_calc(char *t, char *sp, int *s5)
{
	int	f;
	int	count;
	int	s;

	s = 0;
	f = 0;
	count = 0;
	while (sp[s])
		s++;
	*s5 = s;
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

// int	ft_check(char *str, char *charset, int s)
// {
// 	int	i;
// 	int	j;
// 	int	f;

// 	i = 0;
// 	j = 0;
// 	f = 0;
// 	if (str[i] == '\0')
// 		f = 2;
// 	else if (str[i] == charset[i])
// 	{
// 		while (i < s&&str[i])
// 		{
// 			if (str[i] == charset[i])
// 				j++;
// 			else
// 				break ;
// 			i++;
// 		}
// 		if (i == s)
// 			f = 1;
// 	}
// 	return (f);
// }

int	ft_check(char *str, char *charset, int s)
{
	int	i;

	i = 0;
	if (str[i] == '\0')
		return (2);
	while (i < s && str[i])
	{
		if (str[i] != charset[i])
			return (0);
		i++;
	}
	return (1);
}

char	*ft_cpy(char *str, char *charset, int s, int *s2)
{
	int		i;
	int		j;
	char	*t;

	i = 0;
	j = 0;
	while (ft_check(str + j, charset, s) == 0)
		j++;
	t = malloc((j + 1) * sizeof(char));
	while (i < j)
	{
		t[i] = str[i];
		i++;
	}
	t[i] = '\0';
	*s2 = j;
	return (t);
}

char	**ft_split(char *str, char *charset)
{
	int		i;
	int		j;
	int		s1;
	int		s2;
	char	**t;

	i = 0;
	s1 = 0;
	s2 = ft_calc(str, charset, &s1);
	t = malloc(s2 * sizeof(char *));
	while (i < s2)
	{
		if (ft_check(str, charset, s1) == 0)
		{
			t[i++] = ft_cpy(str, charset, s1, &j);
			str += j;
		}
		else if (ft_check(str, charset, s1) == 1)
			str += s1;
		else
			break ;
	}
	t[i] = NULL;
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
