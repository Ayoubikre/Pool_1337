/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Noctis <Noctis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 06:21:27 by Noctis            #+#    #+#             */
/*   Updated: 2024/09/06 06:30:01 by Noctis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int	i;
	int	s;
	int	*t;

	s = max - min;
	while (min >= max)
		return (NULL);
	t = malloc(s * sizeof(int));
	i = 0;
	while (i < s)
	{
		t[i] = min + i;
		i++;
	}
	return (t);
}
