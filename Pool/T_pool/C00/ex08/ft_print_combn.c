/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Noctis <Noctis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/01 00:16:18 by Noctis            #+#    #+#             */
/*   Updated: 2024/09/02 02:36:06 by Noctis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_combn(int n);
int		ft_initialize(int *t1, int *t2, int n);
int		ft_check(int s1);
int		ft_check2(int s1);
void	ft_putnbr(int s, int n);

// int	main(void)
// {
// 	ft_print_combn(9);
// }

void	ft_print_combn(int n)
{
	int	t1[9];
	int	t2[9];
	int	start;
	int	end;
	int	s;

	s = ft_initialize(t1, t2, n - 1);
	start = t1[n - 1];
	end = t2[n - 1];
	while (start < end + 1)
	{
		if (ft_check(start) == 0)
		{
			if (start < s && n != 1)
			{
				write(1, "0", 1);
				ft_putnbr(start, n);
			}
			else
				ft_putnbr(start, n);
			if (start != end)
				write(1, ", ", 2);
		}
		start++;
	}
}

int	ft_initialize(int *t1, int *t2, int n)
{
	int	k;

	k = 10;
	t1[0] = 0;
	t1[1] = 1;
	t1[2] = 12;
	t1[3] = 123;
	t1[4] = 1234;
	t1[5] = 12345;
	t1[6] = 123456;
	t1[7] = 1234567;
	t1[8] = 12345678;
	t2[0] = 9;
	t2[1] = 89;
	t2[2] = 789;
	t2[3] = 6789;
	t2[4] = 56789;
	t2[5] = 456789;
	t2[6] = 3456789;
	t2[7] = 23456789;
	t2[8] = 123456789;
	while (--n > 0)
		k *= 10;
	return (k);
}

int	ft_check(int s1)
{
	int	f;
	int	s2;
	int	mod1;
	int	mod2;

	f = ft_check2(s1);
	while (s1 > 0)
	{
		mod1 = s1 % 10;
		s2 = s1 / 10;
		while (s2 > 0)
		{
			mod2 = s2 % 10;
			if (mod1 == mod2)
				f = 1;
			s2 = s2 / 10;
		}
		s1 = s1 / 10;
	}
	if (f == 1)
		return (1);
	return (0);
}

int	ft_check2(int s1)
{
	int	f;
	int	mod1;
	int	mod2;

	f = 0;
	while (s1 > 0)
	{
		mod1 = s1 % 10;
		mod2 = (s1 / 10) % 10;
		if (mod2 >= mod1)
			f = 1;
		s1 = s1 / 10;
	}
	if (f == 1)
		return (1);
	return (0);
}

void	ft_putnbr(int s, int n)
{
	if (s >= 10)
	{
		ft_putnbr(s / 10, n);
		ft_putnbr(s % 10, n);
	}
	else
		write(1, &(char){s + '0'}, 1);
}
