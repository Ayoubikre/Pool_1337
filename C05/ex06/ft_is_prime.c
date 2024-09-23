/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_prime.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Noctis <Noctis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 16:19:38 by Noctis            #+#    #+#             */
/*   Updated: 2024/09/03 16:33:54 by Noctis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_check(int nb, int i)
{
	if (i == nb)
		return (1);
	if (nb % i == 0)
		return (0);
	return (ft_check(nb, ++i));
}

int	ft_is_prime(int nb)
{
	if (nb < 2)
		return (0);
	if (nb == 2)
		return (1);
	return (ft_check(nb, 2));
}
