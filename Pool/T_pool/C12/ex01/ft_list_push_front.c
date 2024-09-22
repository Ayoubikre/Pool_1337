/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_front.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Noctis <Noctis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 00:58:18 by Noctis            #+#    #+#             */
/*   Updated: 2024/09/22 02:02:42 by Noctis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_list_push_front(t_list **begin_list, void *data)
{
	t_list	*n;

	n = ft_create_elem(data);
	if (n)
	{
		if (*begin_list)
			n->next = *begin_list;
		*begin_list = n;
	}
}
