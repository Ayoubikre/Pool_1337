/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Noctis <Noctis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 22:44:10 by Noctis            #+#    #+#             */
/*   Updated: 2024/09/19 23:20:46 by Noctis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/main.h"

void	add(int n1, int n2)
{
	ft_putnbr((long)n1 + (long)n2);
}

void	sub(int n1, int n2)
{
	ft_putnbr((long)n1 - (long)n2);
}

void	div(int n1, int n2)
{
	if (n2 != 0)
		ft_putnbr((long)n1 / (long)n2);
	else
		ft_putstr(MSG_DIV);
}

void	multi(int n1, int n2)
{
	ft_putnbr((long)n1 * (long)n2);
}

void	mod(int n1, int n2)
{
	if (n2 != 0)
		ft_putnbr((long)n1 % (long)n2);
	else
		ft_putstr(MSG_MOD);
}
