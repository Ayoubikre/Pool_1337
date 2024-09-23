/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Noctis <Noctis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 16:36:15 by Noctis            #+#    #+#             */
/*   Updated: 2024/09/03 16:44:05 by Noctis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_check2(int nb, int i)
{
	if (nb == i)
		return (1);
	if (nb % i == 0)
		return (0);
	return (ft_check2(nb, ++i));
}

int	ft_check(int nb)
{
	if (nb < 2)
		return (0);
	if (nb == 2)
		return (1);
	return (ft_check2(nb, 2));
}

int	ft_find_next_prime(int nb)
{
	while (ft_check(nb) == 0)
		nb++;
	return (nb);
}
