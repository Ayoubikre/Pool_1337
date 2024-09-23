/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Noctis <Noctis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 01:44:14 by Noctis            #+#    #+#             */
/*   Updated: 2024/09/13 20:31:12 by Noctis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include <stdio.h>
#include <unistd.h>

int	ft_check1(char *t, int *s)
{
	int	i;
	int	j;

	i = 0;
	while (t[i])
	{
		if (t[i] < 32 || t[i] > 126 || t[i] == '-' || t[i] == '+')
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
	int	j;

	j = 0;
	while (t[j])
	{
		if (c == t[j])
		{
			*pos = j;
			return (1);
		}
		j++;
	}
	return (0);
}

int	ft_atoi_base(char *str, char *base)
{
	int	i;
	int	f;
	int	r;
	int	s1;

	r = 0;
	f = ft_check1(base, &s1);
	if (f == 1)
	{
		while ((9 <= *str && *str <= 13) || *str == ' ')
			str++;
		while (*str == '-' || *str == '+')
		{
			if (*str == '-')
				f *= -1;
			str++;
		}
		while (ft_check2(*str, base, &i) == 1)
		{
			r = r * s1 + i;
			str++;
		}
	}
	return (r * f);
}

// int	main(void)
// {
// 	int	res;
// 	int	expected;

// 	printf("42:%d\n", ft_atoi_base("2a", "0123456789abcdef"));
// 	printf("-42:%d\n", ft_atoi_base("   --------+-2a", "0123456789abcdef"));
// 	printf("42:%d\n", ft_atoi_base("   -+-2a", "0123456789abcdef"));
// 	printf("0:%d\n", ft_atoi_base("   --------+- 2a", "0123456789abcdef"));
// 	printf("0:%d\n", ft_atoi_base("   --------+-g", "0123456789abcdef"));
// 	printf("0:%d\n", ft_atoi_base("   --------+-2a", ""));
// 	printf("0:%d\n", ft_atoi_base("   --------+-2a", "0"));
// 	printf("0:%d\n", ft_atoi_base("   --------+-2a", "+-0"));
// 	printf("0:%d\n", ft_atoi_base("   --------+-2a", "\t01"));
// 	res = ft_atoi_base(" \v7fffffff", "0123456789abcdef");
// 	printf("%d : %d (equals: %i)\n", INT_MAX, res, INT_MAX == res);
// 	res = ft_atoi_base(" \f-80000000", "0123456789abcdef");
// 	printf("%d : %d (equals: %i)\n", INT_MIN, res, INT_MIN == res);
// 	res = ft_atoi_base("-~~~~~~~~'~~~~~~'~'~~~'''''''~~'$", "'~");
// 	expected = -2143247366;
// 	printf("%d : %d (equals: %i)\n", expected, res, expected == res);
// }
