/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atoi.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Noctis <Noctis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 22:54:04 by Noctis            #+#    #+#             */
/*   Updated: 2024/09/19 23:05:29 by Noctis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/main.h"

int	ft_atoi(char *t)
{
	int	i;
	int	r;
	int	f;

	i = 0;
	r = 0;
	f = 1;
	while ((9 <= t[i] && t[i] <= 13) || t[i] == ' ')
		i++;
	while (t[i] == '+' || t[i] == '-')
	{
		if (t[i] == '-')
			f *= -1;
		i++;
	}
	while ('0' <= t[i] && t[i] <= '9')
	{
		r = r * 10 + t[i] - '0';
		i++;
	}
	return (r * f);
}
