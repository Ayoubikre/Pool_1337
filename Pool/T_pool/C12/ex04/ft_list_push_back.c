/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_back.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Noctis <Noctis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 02:27:41 by Noctis            #+#    #+#             */
/*   Updated: 2024/09/22 04:35:31 by Noctis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_list_push_back(t_list **begin_list, void *data)
{
	t_list	*n;
	t_list	*ptr;

	n = ft_create_elem(data);
	if (n)
	{
		if (*begin_list)
		{
			ptr = ft_list_last(*begin_list);
			ptr->next = n;
		}
		else
			*begin_list = n;
	}
}
