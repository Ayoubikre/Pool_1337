/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Noctis <Noctis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 09:14:23 by Noctis            #+#    #+#             */
/*   Updated: 2024/09/17 19:04:49 by Noctis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int	ft_check(char *t, int *s)
{
	int	i;
	int	j;

	i = 0;
	while (t[i])
	{
		if ((9 <= t[i] && t[i] <= 13) || t[i] == ' ' || t[i] == '+'
			|| t[i] == '-')
			return (0);
		j = i + 1;
		while (t[j])
		{
			if (t[i] == t[j])
				return (0);
			j++;
		}
		i++;
	}
	if (i < 2)
		return (0);
	*s = i;
	return (1);
}

int	ft_check2(char c, char *t, int *pos)
{
	int	i;

	i = 0;
	while (t[i])
	{
		if (t[i] == c)
		{
			*pos = i;
			return (1);
		}
		i++;
	}
	return (0);
}

void	ft_cpy(int nb, char *t1, char *t2, int i)
{
	int	j;

	if (nb < 0)
	{
		j = 1;
		while (--i >= 1)
			t2[j++] = t1[i];
	}
	else
	{
		j = 0;
		while (--i >= 0)
			t2[j++] = t1[i];
	}
	t2[j] = '\0';
}

char	*ft_conv2(int nb, char *base, int s2)
{
	int		i;
	int		j;
	int		k;
	char	*t1;
	char	*t2;

	i = 0;
	j = 0;
	k = nb;
	t1 = malloc(66 * sizeof(int));
	t2 = malloc(66 * sizeof(int));
	if (nb < 0)
	{
		t1[i++] = '-';
		t2[j++] = '-';
		nb *= -1;
	}
	while (nb != 0)
	{
		t1[i++] = base[nb % s2];
		nb = nb / s2;
	}
	t1[i] = '\0';
	ft_cpy(k, t1, t2, i);
	return (t2);
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	int	index_base_from;
	int	f;
	int	r;
	int	s1;
	int	s2;

	f = ft_check(base_from, &s1) * ft_check(base_to, &s2);
	r = 0;
	if (f == 0)
		return (NULL);
	else
	{
		while ((9 <= *nbr && *nbr <= 13) || *nbr == ' ')
			nbr++;
		while (*nbr == '+' || *nbr == '-')
		{
			if (*nbr == '-')
				f *= -1;
			nbr++;
		}
		while (ft_check2(*nbr++, base_from, &index_base_from) == 1)
			r = r * s1 + index_base_from;
	}
	return (ft_conv2(r * f, base_to, s2));
}
