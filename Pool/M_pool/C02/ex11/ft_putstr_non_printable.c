/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakritah <aakritah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/04 08:15:35 by aakritah          #+#    #+#             */
/*   Updated: 2024/08/04 09:06:22 by aakritah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_creat(char *t)
{
	t[0] = '0';
	t[1] = '1';
	t[2] = '2';
	t[3] = '3';
	t[4] = '4';
	t[5] = '5';
	t[6] = '6';
	t[7] = '7';
	t[8] = '8';
	t[9] = '9';
	t[10] = 'a';
	t[11] = 'b';
	t[12] = 'c';
	t[13] = 'd';
	t[14] = 'e';
	t[15] = 'f';
	t[16] = '\0';
}

void	ft_write(int mod, char c)
{
	char	t[17];

	ft_creat(t);
	if (c < 16)
	{
		write(1, "0", 1);
		write(1, &t[mod], 1);
	}
	else
	{
		write(1, "1", 1);
		write(1, &t[mod], 1);
	}
}

void	ft_putstr_non_printable(char *str)
{
	int		i;
	char	c;
	int		mod;

	i = 0;
	while (str[i])
	{
		if (31 < str[i] && str[i] < 127)
			write(1, &str[i], 1);
		else if (0 <= str[i] && str[i] < 32)
		{
			write(1, "\\", 1);
			mod = str[i] % 16;
			c = str[i];
			ft_write(mod, c);
		}
		else if (str[i] == 127)
			write(1, "\\7f", 3);
		i++;
	}
}
