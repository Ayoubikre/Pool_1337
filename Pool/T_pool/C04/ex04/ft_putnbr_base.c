/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Noctis <Noctis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 01:44:33 by Noctis            #+#    #+#             */
/*   Updated: 2024/09/08 07:32:54 by Noctis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_check1(char *t, int *s)
{
	int	i;
	int	j;

	i = 0;
	while (t[i])
	{
		if (t[i] < 32 || t[i] > 126 || t[i] == '-' || t[i] == '+')
			return (0);
		j = i + 1;
		while (t[j])
		{
			if (t[i] == t[j])
				return (0);
			j++;
		}
		i++;
	}
	if (i < 2)
		return (0);
	*s = i;
	return (1);
}

void	ft_putnbr_base(int nbr, char *base)
{
	int	f;
	int	s;

	f = ft_check1(base, &s);
	if (f == 1)
	{
		if (nbr == -2147483648)
		{
			write(1, "-", 1);
			ft_putnbr_base(-(nbr / s), base);
			write(1, &base[-(nbr % s)], 1);
		}
		else if (nbr < 0)
		{
			write(1, "-", 1);
			nbr *= -1;
		}
		if (nbr >= s)
		{
			ft_putnbr_base(nbr / s, base);
			ft_putnbr_base(nbr % s, base);
		}
		else if (0 <= nbr && nbr < s)
			write(1, &base[nbr], 1);
	}
}
