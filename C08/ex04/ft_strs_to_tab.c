/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Noctis <Noctis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 17:50:49 by Noctis            #+#    #+#             */
/*   Updated: 2024/09/17 11:01:16 by Noctis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stock_str.h"

char	*ft_strdup(char *t, int s)
{
	int		i;
	char	*t2;

	i = 0;
	t2 = malloc((s + 1) * sizeof(char));
	if (t2 == NULL)
		return (NULL);
	while (i < s)
	{
		t2[i] = t[i];
		i++;
	}
	t2[i] = '\0';
	return (t2);
}

struct s_stock_str	*ft_strs_to_tab(int ac, char **av)
{
	int			i;
	int			s;
	t_stock_str	*t;

	i = 0;
	t = malloc((ac + 1) * sizeof(t_stock_str));
	if (t == NULL)
		return (NULL);
	while (i < ac)
	{
		s = 0;
		while (av[i][s])
			s++;
		t[i].size = s;
		t[i].str = av[i];
		t[i].copy = ft_strdup(av[i], s);
		i++;
	}
	t[i].size = 0;
	t[i].str = NULL;
	t[i].copy = NULL;
	return (t);
}
