/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_any.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Noctis <Noctis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 22:13:46 by Noctis            #+#    #+#             */
/*   Updated: 2024/09/18 22:19:24 by Noctis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int	ft_any(char **tab, int (*f)(char *))
{
	while (*tab)
		if (f((*tab)++) != 0)
			return (1);
	return (0);
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

// 	i = 0;
// 	array = malloc(3 * sizeof(char *));
// 	array[0] = "A";
// 	array[1] = "Z";
// 	array[2] = NULL;
// 	while (i < 3)
// 	{
// 		printf("%d\n", ft_any(&array[i], ft));
// 		i++;
// 	}
// }
