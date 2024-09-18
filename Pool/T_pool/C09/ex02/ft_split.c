/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Noctis <Noctis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 12:44:22 by Noctis            #+#    #+#             */
/*   Updated: 2024/09/18 15:52:00 by Noctis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

// int	ft_check(char *str, char *charset, int s)
// {
// 	int	i;
// 	int	j;
// 	int	f;

// 	i = 0;
// 	f = 0;
// 	if (str[i] == '\0')
// 		f = 2;
// 	while (i < s && str[j])
// 	{
// 		j = 0;
// 		while (j < s && str[j])
// 		{
// 			if (str[j] == charset[j] || str[i] == charset[j])
// 				f = 1;
// 			j++;
// 			if (j == s)
// 				break ;
// 		}
// 		i++;
// 	}
// 	return (f);
// }

int	ft_check(char *str, char *charset, int s)
{
	int	j;

	j = 0;
	if (*str == '\0')
		return (2);
	while (j < s)
	{
		if (*str == charset[j])
			return (1);
		j++;
	}
	return (0);
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

int	ft_calc(char *t, char *spr, int *ss)
{
	int	f;
	int	count;

	f = 0;
	count = 0;
	while (spr[*ss])
		(*ss)++;
	while (*t)
	{
		if (ft_check(t, spr, *ss) == 0)
		{
			if (f == 0)
			{
				count++;
				f = 1;
			}
			t++;
		}
		else
		{
			f = 0;
			t += *ss;
		}
	}
	return (++count);
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

// int	main(void)
// {
// 	char	str[] = "aaabbbaaaccc";
// 	char	charset[] = "ab";
// 	char	**result;
// 	int		i;

// 	result = ft_split(str, charset);
// 	i = 0;
// 	while (result[i] != NULL)
// 	{
// 		printf("Substring %d: %s\n", i + 1, result[i]);
// 		i++;
// 	}
// 	i = 0;
// 	while (result[i] != NULL)
// 	{
// 		free(result[i]);
// 		i++;
// 	}
// 	free(result);
// 	return (0);
// }

// t_test tests[] = {
//    {
//         .desc = "Empty string with empty charset",
//         .str = "",
//         .charset = "",
//         .expected = (char *[1]) {0},
//     },
//     {
//         .desc = "Single-word string with empty charset",
//         .str = "hello",
//         .charset = "",
//         .expected = (char *[2]) {"hello", 0},
//     },
//     {
//         .desc = "String with leading and trailing separators",
//         .str = ",,hello,world,,",
//         .charset = ",",
//         .expected = (char *[3]) {"hello", "world", 0},
//     },
//     {
//         .desc = "String with multiple consecutive separators",
//         .str = "hello,,,,world",
//         .charset = ",",
//         .expected = (char *[3]) {"hello", "world", 0},
//     },
//     {
//         .desc = "String with repeated separators",
//         .str = "aaabbbaaaccc",
//         .charset = "ab",
//         .expected = (char *[]){ "ccc", 0 },
//     },
// };
