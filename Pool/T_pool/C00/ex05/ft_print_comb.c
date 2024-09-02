/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Noctis <Noctis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 17:11:04 by Noctis            #+#    #+#             */
/*   Updated: 2024/09/02 00:42:00 by Noctis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_write(int i, int j, int k)
{
	if (i == 7 && j == 8 && k == 9)
	{
		write(1, &(char){i + '0'}, 1);
		write(1, &(char){j + '0'}, 1);
		write(1, &(char){k + '0'}, 1);
	}
	else
	{
		write(1, &(char){i + '0'}, 1);
		write(1, &(char){j + '0'}, 1);
		write(1, &(char){k + '0'}, 1);
		write(1, ", ", 2);
	}
}

void	ft_print_comb(void)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	j = 0;
	k = 0;
	while (i <= 7)
	{
		j = i + 1;
		while (j <= 8)
		{
			k = j + 1;
			while (k <= 9)
			{
				ft_write(i, j, k);
				k++;
			}
			j++;
		}
		i++;
	}
}

// int	main(void)
// {
// 	ft_print_comb();
// }
