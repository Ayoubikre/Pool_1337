/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_if.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Noctis <Noctis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 22:13:04 by Noctis            #+#    #+#             */
/*   Updated: 2024/09/18 22:22:51 by Noctis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int	ft_count_if(char **tab, int length, int (*f)(char *))
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (i < length)
	{
		if (f(tab[i]) != 0)
			count++;
		i++;
	}
	return (count);
}

// int	ft(char *str)
// {
// 	if (*str == 'A')
// 		return (1);
// 	return (0);
// }
// int	main(void)
// {
// 	char	**array;
// 	int		i;

// 	array = malloc(3 * sizeof(char *));
// 	array[0] = "A";
// 	array[1] = "Z";
// 	array[2] = "A";
// 	array[3] = "NULL";
// 	printf("%d\n", ft_count_if(array, 3, ft));
// }
