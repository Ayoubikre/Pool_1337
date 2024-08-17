/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakritah <aakritah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 15:42:22 by aakritah          #+#    #+#             */
/*   Updated: 2024/08/12 15:43:38 by aakritah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	int	i;
	int	s;
	int	*t;

	if (min >= max)
	{
		range[0] = NULL;
		return (0);
	}
	s = max - min;
	t = malloc(s * sizeof(int));
	if (t == NULL)
		return (-1);
	i = 0;
	while (i < s)
	{
		t[i] = min + i;
		i++;
	}
	range[0] = t;
	return (s);
}
