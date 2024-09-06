/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Noctis <Noctis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 06:26:04 by Noctis            #+#    #+#             */
/*   Updated: 2024/09/06 06:35:24 by Noctis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	int	i;
	int	s;
	int	*t;

	i = 0;
	s = max - min;
	if (min >= max)
	{
		range[0] = NULL;
		return (0);
	}
	t = malloc(sizeof(int) * s);
	while (i < s)
	{
		t[i] = min + i;
		i++;
	}
	range[0] = t;
	return (s);
}
