/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush02.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakritah <aakritah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/28 19:19:59 by moel-idr          #+#    #+#             */
/*   Updated: 2024/07/29 08:38:53 by aakritah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char n);

void	rush(int x, int y)
{
	int	j;
	int	i;

	i = 0;
	if (y < 1 || x < 1)
		return ;
	while (i < y)
	{
		j = 0;
		while (j < x)
		{
			if (i == 0 && (j == 0 || j == x - 1))
				ft_putchar('A');
			else if (i == y - 1 && (j == 0 || j == x - 1))
				ft_putchar('C');
			else if ((i == 0 || i == y - 1) || (j == 0 || j == x - 1))
				ft_putchar('B');
			else
				ft_putchar(' ');
			j++;
		}
		ft_putchar('\n');
		i++;
	}
}
