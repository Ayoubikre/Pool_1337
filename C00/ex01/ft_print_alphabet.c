/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_alphabet.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Noctis <Noctis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 17:09:16 by Noctis            #+#    #+#             */
/*   Updated: 2024/08/27 17:09:50 by Noctis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_alphabet(void)
{
	int	i;

	i = 0;
	while (i < 26)
	{
		write(1, &(char){'a' + i}, 1);
		i++;
	}
}
