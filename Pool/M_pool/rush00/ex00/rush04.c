/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush04.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moel-idr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/28 19:20:32 by moel-idr          #+#    #+#             */
/*   Updated: 2024/07/28 19:20:36 by moel-idr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char n);

void	check_conditions(int x, int y, int i, int j)
{
	if (x == 1 || y == 1)
	{
		if (i == 0 && j == 0)
			ft_putchar('A');
		else if ((i == 0 && j == y - 1) || (i == x - 1 && j == 0))
			ft_putchar('C');
		else 
			ft_putchar('B');
	}
	else if ((i == 0 && j == 0) || (i == x - 1 && j == y - 1))
		ft_putchar('A');
	else if ((i == 0 && j == y - 1) || (i == x - 1 && j == 0))
		ft_putchar('C');
	else if ((i == 0 || i == x - 1) || (j == 0 || j == y - 1))
		ft_putchar('B');
	else
		ft_putchar(' ');
}

void	rush(int y, int x)
{
	int		j;
	int		i;

	i = 0;
	if (x < 1 || y < 1)
		return ;
	while (i < x)
	{
		j = 0;
		while (j < y)
		{
			check_conditions(x, y, i, j);
			j++;
		}
		ft_putchar('\n');
		i++;
	}
}
