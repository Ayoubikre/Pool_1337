/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_string_tab.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Noctis <Noctis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 16:40:59 by Noctis            #+#    #+#             */
/*   Updated: 2024/09/20 17:33:57 by Noctis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int	ft_strcmp(char *t1, char *t2)
{
	int	i;

	i = 0;
	while (t1[i] && t1[i] == t2[i])
		i++;
	return (t1[i] - t2[i]);
}

void	ft_sort_string_tab(char **tab)
{
	int		i;
	int		j;
	char	*tmp;

	i = 1;
	while (tab[i])
	{
		j = i;
		tmp = tab[i];
		while (j > 0 && ft_strcmp(tab[j - 1], tmp) > 0)
		{
			tab[j] = tab[j - 1];
			j--;
		}
		tab[j] = tmp;
		i++;
	}
}
// int	main(void)
// {
// 	int		i;
// 	char	*tab[] = {"2", "1", "3", "a", "6", "d", NULL};

// 	i = 0;
// 	while (tab[i])
// 		printf("tab[%d] = %s\n", i, tab[i++]);

// 	ft_sort_string_tab(tab);
// 	printf("\n");

// 	i = 0;
// 	while (tab[i])
// 		printf("tab[%d] = %s\n", i, tab[i++]);
// }
