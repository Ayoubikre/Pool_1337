/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakritah <aakritah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/28 19:18:43 by moel-idr          #+#    #+#             */
/*   Updated: 2024/07/29 18:38:50 by aakritah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char n)
{
	write(1, &n, 1);
}
