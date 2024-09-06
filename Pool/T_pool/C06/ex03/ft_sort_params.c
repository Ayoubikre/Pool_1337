/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Noctis <Noctis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 20:43:28 by Noctis            #+#    #+#             */
/*   Updated: 2024/09/06 05:36:30 by Noctis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_strcmp(char *s1, char *s2)
{
	while (*s1 && *s2 && *s1 == *s2)
	{
		s1++;
		s2++;
	}
	return (*s1 - *s2);
}

int	main(int c, char **t)
{
	int		i;
	int		j;
	char	*key;

	i = 2;
	while (i < c)
	{
		j = i - 1;
		key = t[i];
		while (j >= 1 && ft_strcmp(key, t[j]) < 0)
		{
			t[j + 1] = t[j];
			j--;
		}
		t[j + 1] = key;
		i++;
	}
	i = 1;
	while (i < c)
	{
		while (*t[i])
			write(1, (t[i])++, 1);
		write(1, "\n", 1);
		i++;
	}
}
