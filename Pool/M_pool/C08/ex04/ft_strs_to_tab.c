/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakritah <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 10:12:46 by aakritah          #+#    #+#             */
/*   Updated: 2024/08/15 10:12:48 by aakritah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stock_str.h"
#include "stdlib.h"
#include "stdio.h"

int	ft_copy(char *str, char *dest)
{
	int	i;

	i = 0;
	while (str[i])
	{
		dest[i] = str[i];
		i++;
	}
	dest[i] = '\0';
	return (i);
}

int	len(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

struct s_stock_str	*ft_strs_to_tab(int ac, char **av)
{
	t_stock_str	*pstock;
	int			i;

	pstock = (t_stock_str *)malloc((ac + 1) * sizeof(t_stock_str));
	if (!pstock)
		return (NULL);
	i = 0;
	while (i < ac)
	{
		pstock[i].size = len(av[i]);
		pstock[i].str = av[i];
		pstock[i].copy = (char *)malloc(len(av[i]) + 1);
		if (!pstock[i].copy)
			return (NULL);
		pstock[i].copy[0] = '\0';
		ft_copy(av[i], pstock[i].copy);
		i++;
	}
	pstock[i].str = 0;
	return (pstock);
}

// int main (int ac, char **av)
// {
// 	av ++;
// 	ac --;
// 	struct s_stock_str *arr = ft_strs_to_tab(ac,av);
// 	int i = 0;
// 	while (i < ac)
// 	{
// 		printf("%d ", arr[i].size);
// 		printf("%s ", arr[i].str);
// 		printf("%s ", arr[i].copy);
// 		printf("|| ");
// 		i++;
// 	}
// }