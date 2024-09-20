/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_foreach.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Noctis <Noctis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 20:54:40 by Noctis            #+#    #+#             */
/*   Updated: 2024/09/18 22:21:58 by Noctis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>

void	ft_foreach(int *tab, int length, void (*f)(int))
{
	int	i;

	i = 0;
	while (i < length)
	{
		f(tab[i]);
		i++;
	}
}

// void	ft_putnbr(int nb)
// {
// 	if (nb == -2147483648)
// 	{
// 		ft_putchar('-');
// 		ft_putchar('2');
// 		ft_putnbr(147483648);
// 	}
// 	else if (nb < 0)
// 	{
// 		ft_putchar('-');
// 		nb = -nb;
// 		ft_putnbr(nb);
// 	}
// 	else if (nb > 9)
// 	{
// 		ft_putnbr(nb / 10);
// 		ft_putnbr(nb % 10);
// 	}
// 	else
// 		write(1, &(char){nb + '0'}, 1);
// }

// int	main(void)
// {
// 	int i;
// 	int *tab;
// 	int length;

// 	length = 10;
// 	tab = malloc(length * sizeof(int));
// 	i = 0;
// 	while (i < length)
// 	{
// 		tab[i] = i;
// 		i++;
// 	}
// 	ft_foreach(tab, length, &ft_putnbr);
// }