/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_abs.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Noctis <Noctis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 16:44:50 by Noctis            #+#    #+#             */
/*   Updated: 2024/09/16 17:09:25 by Noctis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_ABS_H
# define FT_ABS_H

static inline int	ft_abs(int Value)
{
	if (Value < 0)
		Value *= -1;
	return (Value);
}
# define ABS(Value) ft_abs(Value);

#endif