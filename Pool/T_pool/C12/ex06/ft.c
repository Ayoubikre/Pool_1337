/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Noctis <Noctis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 17:53:58 by Noctis            #+#    #+#             */
/*   Updated: 2024/09/22 04:56:14 by Noctis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

int	main(int argc, char**argv)
{
	int		i;
	int		*data;
	t_list	*list;
	t_list	*ptr;
	t_list	*tmp;

	// creat list
	list = NULL;
	i = 1;
	while (i <= 15)
	{
		data = malloc(sizeof(int));
		if (data)
		{
			*data = i;
			ft_list_push_front(&list, data);
		}
		i++;
	}
		// print size
	printf("size = %i\n\n", ft_list_size(list));
		// print list
	ptr = list;
	while (ptr != NULL)
	{
		printf("data = %i\n", *(int *)ptr->data);
		ptr = ptr->next;
	}
		//print last elemnt
	ptr = ft_list_last(list);
	printf("\nlast 1 = %i\n", *(int *)ptr->data);
	printf("\n---------------\n\n");
		
	    		//  strings
	// int		index=0;
	// t_list	*current;
	// current = ft_list_push_strs(argc, argv);
	// while (current != 0)
	// {
	// 	printf("list[%d] = $%s$\n", index++, (char *)current->data);
	// 	current = current->next;
	// }
	
	ptr = list;
	while (ptr)
	{
		tmp = ptr;
		ptr = ptr->next;
		free(tmp->data);
		free(tmp);
	}
}

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

t_list	*ft_list_last(t_list *begin_list)
{
	while (begin_list->next)
		begin_list = begin_list->next;
	return (begin_list);
}
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
t_list	*ft_list_push_strs(int size, char **strs)
{
	t_list	*list;
	int		i;

	i = 0;
	list = NULL;
	while (i < size)
		ft_list_push_front(&list, strs[i++]);
	return (list);
}
