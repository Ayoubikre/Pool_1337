/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_params.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakritah <aakritah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/10 17:57:13 by aakritah          #+#    #+#             */
/*   Updated: 2024/08/10 17:58:46 by aakritah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	main(int argc, char **argv)
{
	int	i;
	int	s;

	i = 1;
	while (i < argc)
	{
		s = 0;
		while (argv[i][s])
			s++;
		write(1, &argv[i][0], s);
		write(1, "\n", 1);
		i++;
	}
}
