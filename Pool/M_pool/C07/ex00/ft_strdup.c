/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakritah <aakritah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 15:33:02 by aakritah          #+#    #+#             */
/*   Updated: 2024/08/12 15:34:17 by aakritah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

char	*ft_strdup(char *src)
{
	char	*t;
	int		i;
	int		s;

	s = 0;
	while (src[s])
		s++;
	t = malloc((s + 1) * sizeof(char));
	if (t == NULL)
		return (NULL);
	i = 0;
	while (src[i])
	{
		t[i] = src[i];
		i++;
	}
	t[i] = '\0';
	return (t);
}
