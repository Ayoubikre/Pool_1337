/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_params.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakritah <aakritah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/10 17:59:03 by aakritah          #+#    #+#             */
/*   Updated: 2024/08/10 17:59:37 by aakritah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	main(int argc, char **argv)
{
	int	i;
	int	s;

	i = argc - 1;
	while (i > 0)
	{
		s = 0;
		while (argv[i][s])
			s++;
		write(1, &argv[i][0], s);
		write(1, "\n", 1);
		i--;
	}
}
