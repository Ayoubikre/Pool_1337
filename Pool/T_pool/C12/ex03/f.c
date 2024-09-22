/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Noctis <Noctis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 17:53:58 by Noctis            #+#    #+#             */
/*   Updated: 2024/09/22 02:07:03 by Noctis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

t_list	*ft_create_elem(void *data)
{
	t_list	*n;

	n = malloc(sizeof(t_list));
	if (!n)
		return (NULL);
	n->data = data;
	n->next = NULL;
	return (n);
}

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

int	ft_list_size(t_list *begin_list)
{
	int	count;

	count = 0;
	while (begin_list)
	{
		count++;
		begin_list = begin_list->next;
	}
	return (count);
}
