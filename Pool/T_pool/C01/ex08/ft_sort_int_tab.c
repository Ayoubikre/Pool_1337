/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Noctis <Noctis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 03:49:58 by Noctis            #+#    #+#             */
/*   Updated: 2024/09/02 17:52:03 by Noctis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

                    /* https://www.geeksforgeeks.org/insertion-sort-algorithm/ */

//
//
//                     Selection Sort Algorithm :
//
//

void	ft_sort_int_tab(int *tab, int size)
{
	int	i;
	int	j;
	int	min_id;
	int	tmp;

	i = 0;
	while (i < size - 1)
	{
		j = i + 1;
		min_id = i;
		while (j < size)
		{
			if (tab[min_id] > tab[j])
				min_id = j;
			j++;
		}
		tmp = tab[i];
		tab[i] = tab[min_id];
		tab[min_id] = tmp;
		i++;
	}
}

//
//
//                     Bubble Sort Algorithm :
//
//

void	ft_sort_int_tab(int *tab, int size)
{
	int	i;
	int	j;
	int	tmp;

	int f; // break if its sorted but loop not ended
	i = 0;
	while (i < size)
	{
		j = i;
		f = 0;
		while (j < size - 1)
		{
			if (tab[j] > tab[j + 1])
			{
				tmp = tab[j];
				tab[j] = tab[j + 1];
				tab[j + 1] = tmp;
				f = 1;
			}
			j++;
		}
		size--;
		if (f == 0)
			break ;
	}
}

//
//
//                     Insertion Sort Algorithm :
//
//

void	ft_sort_int_tab(int *tab, int size)
{
	int	i;
	int	j;
	int	key;

	i = 1;
	while (i < size)
	{
		key = tab[i];
		j = i - 1;
		while (j >= 0 && key < tab[j]) // revers order with key > tab[j]
		{
			tab[j + 1] = tab[j];
			j--;
		}
		tab[j + 1] = key;
		i++;
	}
}

// int	main(void)
// {
// 	int	t[] = {10, 5, 3, 25, 20, 16, 1, 100};

// 	for (int i = 0; i < 8; i++)
// 		printf("| %d |", t[i]);
//
// 	printf("\n");
// 	ft_sort_int_tab(t, 8);
// 	printf("\n");
//
// 	for (int i = 0; i < 8; i++)
// 		printf("| %d |", t[i]);
// }
