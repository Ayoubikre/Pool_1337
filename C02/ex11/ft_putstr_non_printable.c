/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Noctis <Noctis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 01:04:15 by Noctis            #+#    #+#             */
/*   Updated: 2024/09/06 21:48:49 by Noctis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putstr_non_printable(char *str)
{
	unsigned char	n;

	while (*str)
	{
		if (*str > 31 && *str < 127)
			write(1, str, 1);
		if (*str < 32 || *str > 126)
		{
			n = (unsigned char)*str;
			write(1, "\\", 1);
			if ((n / 16) < 10)
				write(1, &(char){(n / 16) + '0'}, 1);
			else
				write(1, &(char){((n / 16) - 10) + 'a'}, 1);
			if ((n % 16) < 10)
				write(1, &(char){(n % 16) + '0'}, 1);
			else
				write(1, &(char){((n % 16) - 10) + 'a'}, 1);
		}
		str++;
	}
}
