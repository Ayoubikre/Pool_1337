/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakritah <aakritah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 15:35:02 by aakritah          #+#    #+#             */
/*   Updated: 2024/08/12 15:36:47 by aakritah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int	*t;
	int	i;
	int	s;

	if (min >= max)
		return (NULL);
	s = max - min;
	t = malloc(s * sizeof(int));
	if (t == NULL)
		return (NULL);
	i = 0;
	while (i < s)
	{
		t[i] = min + i;
		i++;
	}
	return (t);
}
