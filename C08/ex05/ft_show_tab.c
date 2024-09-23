/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_show_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Noctis <Noctis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 17:51:18 by Noctis            #+#    #+#             */
/*   Updated: 2024/09/17 11:02:58 by Noctis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "../ex04/ft_strs_to_tab.c"
#include <unistd.h>

void	ft_putnbr(int nb)
{
	if (nb > 9)
	{
		ft_putnbr(nb / 10);
		ft_putnbr(nb % 10);
	}
	else if (0 <= nb && nb <= 9)
		write(1, &(char){nb + '0'}, 1);
}

void	ft_putstr(char *t)
{
	while (*t)
		write(1, t++, 1);
}

void	ft_show_tab(struct s_stock_str *par)
{
	int	i;

	i = 0;
	while (par[i].str != NULL)
	{
		ft_putnbr(par[i].size);
		write(1, "\n", 1);
		ft_putstr(par[i].str);
		write(1, "\n", 1);
		ft_putstr(par[i].copy);
		write(1, "\n", 1);
		i++;
	}
}

// int	main(void)
// {
// 	char	*t[] = {"heelo", "this", "a", "test"};

// 	ft_show_tab(ft_strs_to_tab(4, t));
// 	return (0);
// }
