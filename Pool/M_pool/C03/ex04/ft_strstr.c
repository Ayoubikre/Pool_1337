/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakritah <aakritah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 15:56:56 by aakritah          #+#    #+#             */
/*   Updated: 2024/08/14 11:15:11 by aakritah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

char	*ft_strstr(char *str, char *to_find)
{
	int	i;
	int	j;
	int	s;

	i = 0;
	s = 0;
	if (to_find[0] == '\0')
		return (str);
	while (to_find[s])
		s++;
	while (str[i])
	{
		j = 0;
		while (to_find[j])
		{
			if (str[j + i] == to_find[j])
				j++;
			else
				break ;
		}
		if (j == s)
			return (str + i);
		i++;
	}
	return (NULL);
}
