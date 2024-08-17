/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush00.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moel-idr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/28 19:19:41 by moel-idr          #+#    #+#             */
/*   Updated: 2024/07/28 19:19:48 by moel-idr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char n);

void	check_conditions(int x, int y, int j, int i)
{
	if (i == 0 && (j == 0 || j == x - 1))
		ft_putchar('o');
	else if (i == y - 1 && (j == 0 || j == x - 1))
		ft_putchar('o');
	else if ((i == 0 || i == y - 1))
		ft_putchar('-');
	else if ((j == 0 || j == x - 1))
		ft_putchar('|');
	else
		ft_putchar(' ');
}

void	rush(int x, int y)
{
	int		j;
	int		i;

	i = 0;
	if (y < 1 || x < 1)
		return ;
	while (i < y)
	{
		j = 0;
		while (j < x)
		{
			check_conditions(x, y, j, i);
			j++;
		}
		ft_putchar('\n');
		i++;
	}
}
