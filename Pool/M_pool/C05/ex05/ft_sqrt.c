/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakritah <aakritah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 17:41:31 by aakritah          #+#    #+#             */
/*   Updated: 2024/08/12 18:08:09 by aakritah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_find(int nb, int i)
{
	if (i * i == nb)
		return (i);
	if (i * i > nb)
		return (0);
	return (ft_find(nb, i + 1));
}

int	ft_sqrt(int nb)
{
	int	i;

	i = ft_find(nb, 1);
	return (i);
}
