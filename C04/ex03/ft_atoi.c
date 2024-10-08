/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Noctis <Noctis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 01:30:37 by Noctis            #+#    #+#             */
/*   Updated: 2024/09/03 01:42:30 by Noctis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi(char *str)
{
	int	f;
	int	r;

	f = 1;
	r = 0;
	while ((9 <= *str && *str <= 13) || *str == ' ')
		str++;
	while (*str == '+' || *str == '-')
	{
		if (*str == '-')
			f *= -1;
		str++;
	}
	while ('0' <= *str && *str <= '9')
	{
		r = r * 10 + (*str - '0');
		str++;
	}
	return (r * f);
}
