/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Noctis <Noctis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 06:36:44 by Noctis            #+#    #+#             */
/*   Updated: 2024/09/14 21:55:53 by Noctis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int	ft_cal(int size, char **strs, char *sep)
{
	int	i;
	int	j;
	int	s1;

	i = 0;
	s1 = 0;
	while (i < size)
	{
		j = 0;
		while (strs[i][j])
		{
			s1++;
			j++;
		}
		i++;
	}
	i = 0;
	while (sep[i])
		i++;
	s1 += (i * (size - 1));
	return (++s1);
}

void	ft_strcat(char *s1, char *s2)
{
	int	i;
	int	j;

	i = 0;
	while (s1[i])
		i++;
	j = 0;
	while (s2[j])
	{
		s1[i + j] = s2[j];
		j++;
	}
	s1[i + j] = '\0';
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	int		i;
	char	*t;
	int		s1;

	i = 0;
	s1 = ft_cal(size, strs, sep);
	t = malloc(s1 * sizeof(char));
	if (t == NULL)
		return (NULL);
	t[0] = '\0';
	if (size == 0)
		return (t);
	else
	{
		while (strs[i])
		{
			ft_strcat(t, strs[i]);
			if (i < size - 1)
				ft_strcat(t, sep);
			i++;
		}
	}
	t[s1 - 1] = '\0';
	return (t);
}
