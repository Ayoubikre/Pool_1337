/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakritah <aakritah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 17:41:58 by aakritah          #+#    #+#             */
/*   Updated: 2024/08/12 18:10:36 by aakritah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_test(int nb, int i)
{
	if (i == 1)
		return (1);
	else if (nb % i == 0)
		return (0);
	return (ft_test(nb, i - 1));
}

int	ft_is_prime(int nb)
{
	if (nb <= 1)
		return (0);
	if (nb == 2)
		return (1);
	return (ft_test(nb, nb / 2));
}

int	ft_find_next_prime(int nb)
{
	if (ft_is_prime(nb) == 0)
		return (ft_find_next_prime(nb + 1));
	return (nb);
}
