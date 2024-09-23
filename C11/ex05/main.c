/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Noctis <Noctis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 18:35:11 by Noctis            #+#    #+#             */
/*   Updated: 2024/09/19 23:03:39 by Noctis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/main.h"

int	main(int ac, char **ar)
{
	int		i;
	int		flg;
	char	*t[6];
	void	(*f[5])(int, int);

	ft_remplire(t, f);
	flg = 0;
	if (ac == 4)
	{
		i = 0;
		while (t[i])
		{
			if (ft_strcmp(t[i], ar[2]) == 0)
			{
				ft_calcul(ar[1], ar[3], f[i]);
				flg = 1;
				break ;
			}
			i++;
		}
		if (flg == 0)
			ft_putnbr(0);
	}
	return (0);
}
