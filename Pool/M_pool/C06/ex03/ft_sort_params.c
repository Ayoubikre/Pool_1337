/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakritah <aakritah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/10 18:00:06 by aakritah          #+#    #+#             */
/*   Updated: 2024/08/14 11:02:22 by aakritah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s2[i] && s1[i] && s1[i] == s2[i])
		i++;
	return (s1[i] - s2[i]);
}

void	ft_write(int argc, char **argv)
{
	int	i;
	int	k;

	i = 1;
	while (i < argc)
	{
		k = 0;
		while (argv[i][k])
			k++;
		write(1, &argv[i][0], k);
		write(1, "\n", 1);
		i++;
	}
}

int	main(int argc, char **argv)
{
	char	*t;
	int		i;
	int		j;
	int		k;

	i = 1;
	k = argc;
	while (i < k)
	{
		j = i + 1;
		while (j < argc)
		{
			if (ft_strcmp(argv[j], argv[j - 1]) < 0)
			{
				t = argv[j];
				argv[j] = argv[j - 1];
				argv[j - 1] = t;
			}
			j++;
		}
		k--;
	}
	ft_write(argc, argv);
}
