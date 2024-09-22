/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Noctis <Noctis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 17:53:58 by Noctis            #+#    #+#             */
/*   Updated: 2024/09/22 02:23:17 by Noctis           ###   ########.fr       */
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

int	main(void)
{
	int		i;
	int		*data;
	t_list	*list;
	t_list	*ptr;
	t_list	*tmp;

	list = NULL;
	i = 4;
	while (i < 16)
	{
		data = malloc(sizeof(int));
		if (data)
		{
			*data = i;
			ft_list_push_front(&list, data);
		}
		i++;
	}
	ptr = list;
	printf("size = %i\n", ft_list_size(ptr));
	printf("\n---------------\n");
	while (ptr != NULL)
	{
		printf("data = %i\n", *(int *)ptr->data);
		ptr = ptr->next;
	}
	ptr = ft_list_last(list);
	printf("\n---------------\n");
	printf("last = %i\n", *(int *)ptr->data);
	ptr = list;
	while (ptr)
	{
		tmp = ptr;
		ptr = ptr->next;
		free(tmp->data);
		free(tmp);
	}
}
