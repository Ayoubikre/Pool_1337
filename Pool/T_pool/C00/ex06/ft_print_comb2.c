/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Noctis <Noctis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 01:16:55 by Noctis            #+#    #+#             */
/*   Updated: 2024/08/31 22:55:48 by Noctis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_write(int k)
{
	int	div;
	int	mod;

	if (k < 10)
	{
		write(1, "0", 1);
		write(1, &(char){k + '0'}, 1);
	}
	else
	{
		div = k / 10;
		mod = k % 10;
		write(1, &(char){div + '0'}, 1);
		write(1, &(char){mod + '0'}, 1);
	}
}

void	ft_check(int i, int j)
{
	if (!(i == 98 && j == 99))
		write(1, ", ", 2);
}

void	ft_print_comb2(void)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < 99)
	{
		j = i + 1;
		while (j < 100)
		{
			ft_write(i);
			write(1, " ", 1);
			ft_write(j);
			ft_check(i, j);
			j++;
		}
		i++;
	}
}
