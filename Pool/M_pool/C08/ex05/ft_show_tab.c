/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_show_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakritah <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 10:12:59 by aakritah          #+#    #+#             */
/*   Updated: 2024/08/15 10:13:01 by aakritah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stock_str.h"
#include "unistd.h"

void	printchar(char c)
{
	write(1, &c, 1);
}

void	print(char *str)
{
	while (*str)
		write(1, str++, 1);
}

void	ft_putnbr(unsigned int nb)
{
	if (nb >= 10)
		ft_putnbr(nb / 10);
	printchar((nb % 10) + '0');
}

void	ft_show_tab(struct s_stock_str *par)
{
	int	i;

	i = 0;
	while (par[i].str != 0)
	{
		print(par[i].str);
		printchar('\n');
		ft_putnbr((unsigned int)par[i].size);
		printchar('\n');
		print(par[i].copy);
		printchar('\n');
		i++ ;
	}
}
