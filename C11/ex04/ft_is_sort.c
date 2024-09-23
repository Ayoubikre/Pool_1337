/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Noctis <Noctis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 22:23:25 by Noctis            #+#    #+#             */
/*   Updated: 2024/09/19 18:28:17 by Noctis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int	ft_is_sort(int *tab, int length, int (*f)(int, int))
{
	int	i;
	int	f1;
	int	f2;

	f1 = 1;
	f2 = 1;
	i = 0;
	while (i++ < length - 2)
	{
		if (f(tab[i], tab[i + 1]) > 0)
			f1 = 0;
		if (f(tab[i], tab[i + 1]) < 0)
			f2 = 0;
	}
	if (f1 + f2 > 0)
		return (1);
	return (0);
}

// int	ft_tri(int a, int b)
// {
// 	return (a - b);
// }

// int	main(void)
// {
//	static int	tabx[] = {7, 6, 6, 6, 5, 5, 3, 2, 2, 1, 1, 0, 0};
//	static int	tabx[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
// 	int length = 10;

// 	printf("%d\n", ft_is_sort(tabx, length, &ft_tri));
// 	return (0);
// }