/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Noctis <Noctis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 05:46:35 by Noctis            #+#    #+#             */
/*   Updated: 2024/09/06 06:10:53 by Noctis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strdup(char *src)
{
	int		s;
	char	*t;

	s = 0;
	while (src[s])
		s++;
	t = malloc(sizeof(char) * (s + 1));
	if (t == NULL)
		return (NULL);
	while (*src)
		*t++ = *src++;
	*t = '\0';
	return (t - s);
}
