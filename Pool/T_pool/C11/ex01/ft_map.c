/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Noctis <Noctis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 21:50:45 by Noctis            #+#    #+#             */
/*   Updated: 2024/09/18 22:20:35 by Noctis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int	*ft_map(int *tab, int length, int (*f)(int))
{
	int	i;
	int	*t;

	i = 0;
	t = malloc(length * sizeof(int));
	if (!t)
		return (NULL);
	while (i < length)
	{
		t[i] = f(tab[i]);
		i++;
	}
	return (t);
}

// int	ft_mul(int a)
// {
// 	return (a * 2);
// }

// int	main(void)
// {
// 	int i;
// 	int *tab;
// 	int length;
// 	int *res;

// 	tab = malloc(length * sizeof(int));
// 	length = 10;
// 	i = 0;
// 	while (i < length)
// 	{
// 		tab[i] = i;
// 		i++;
// 	}
// 	res = ft_map(tab, length, &ft_mul);
// 	i = 0;
// 	while (i < length)
// 	{
// 		printf("%i", res[i]);
// 		i++;
// 	}
// }