/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakritah <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 08:50:10 by aakritah          #+#    #+#             */
/*   Updated: 2024/07/25 12:01:40 by aakritah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putnbr(int nb)
{
	int		div;
	int		mod;

	if (nb == -2147483648)
		write(1, "-2147483648", 11);
	else if (nb < 0)
	{
		write(1, "-", 1);
		nb *= -1;
	}
	if (nb >= 10)
	{
		div = nb / 10;
		mod = nb % 10;
		ft_putnbr(div);
		ft_putnbr(mod);
	}
	else if (nb < 10 && nb >= 0)
	{
		nb = nb + '0';
		write(1, &nb, 1);
	}
}
