/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Noctis <Noctis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 16:00:33 by Noctis            #+#    #+#             */
/*   Updated: 2024/09/03 16:44:53 by Noctis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

                                //  normal :

int	ft_sqrt(int nb)
{
	int	i;

	i = 0;
	while (i < nb / 2)
	{
		if (i * i == nb)
			return (i);
		i++;
	}
	return (0);
}


                                // recursize :

int	ft_find(int nb, int i)
{
	if (i * i == nb)
		return (i);
	if (i > nb / 2)
		return (0);
	return (ft_find(nb, ++i));
}

int	ft_sqrt(int nb)
{
	int	i;

	i = ft_find(nb, 1);
	return (i);
}
