/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakritah <aakritah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 10:07:59 by aakritah          #+#    #+#             */
/*   Updated: 2024/08/13 19:47:04 by aakritah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

char	*ft_strcat(char *dest, char *src)
{
	int	i;
	int	s;

	i = 0;
	s = 0;
	while (dest[s])
		s++;
	while (src[i])
	{
		dest[s + i] = src[i];
		i++;
	}
	dest[s + i] = '\0';
	return (dest);
}

int	ft_size(int size, char **strs, char *sep)
{
	int	s;
	int	s2;
	int	i;

	i = 0;
	s = 0;
	while (i < size)
	{
		s2 = 0;
		while (strs[i][s2])
		{
			s++;
			s2++;
		}
		i++;
	}
	s++;
	s2 = 0;
	while (sep[s2])
		s2++;
	s2 = s2 * (size - 1);
	s += s2;
	return (s);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	int		s;
	int		i;
	char	*t;

	if (size == 0)
	{
		t = malloc(1 * sizeof(char));
		return (t);
	}
	s = ft_size(size, strs, sep);
	t = malloc(s * sizeof(char));
	if (t == NULL)
		return (NULL);
	t[0] = '\0';
	i = 0;
	while (i < size)
	{
		ft_strcat(t, strs[i]);
		if (i < (size - 1))
			ft_strcat(t, sep);
		i++;
	}
	t[s] = '\0';
	return (t);
}
