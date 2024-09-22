/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_reverse.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Noctis <Noctis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 14:34:13 by Noctis            #+#    #+#             */
/*   Updated: 2024/09/22 22:35:06 by Noctis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_list_reverse(t_list **begin_list)
{
	t_list	*prev;
	t_list	*cr;
	t_list	*next;

	if (*begin_list == 0)
		return ;
	prev = NULL;
	cr = *begin_list;
	while (cr)
	{
		next = cr->next;
		cr->next = prev;
		prev = cr;
		cr = next;
	}
	*begin_list = prev;
}
