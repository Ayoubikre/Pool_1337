/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Noctis <Noctis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 17:53:58 by Noctis            #+#    #+#             */
/*   Updated: 2024/09/22 22:30:46 by Noctis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

int	main()
{
	int		i;
	int		*data;
	t_list	*list;
	t_list	*ptr;
	// t_list	*tmp;
	void	(*free_fct)(void *);

	// creat list
	list = NULL;
	i = 0;
	while (i < 15)
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
	
	// reverse list	
	ft_list_reverse(&list);
	ptr = list;
	while (ptr)
	{
		printf("data = %i\n", *(int *)ptr->data);
		ptr = ptr->next;
	}

	printf("\n---------------\n\n");
	
	
	free_fct = ft_free;
	ft_list_clear(list, free_fct);
	// ptr = list;
	// while (ptr)
	// {
	// 	tmp = ptr;
	// 	ptr = ptr->next;
	// 	free(tmp->data);
	// 	free(tmp);
	// }
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
void	ft_free(void *data)
{
	free(data);
}

void	ft_list_clear(t_list *begin_list, void (*free_fct)(void *))
{
	t_list	*ptr;

	while (begin_list)
	{
		ptr = begin_list;
		begin_list = begin_list->next;
		free_fct(ptr->data);
		free(ptr);
	}
}
t_list	*ft_list_at(t_list *begin_list, unsigned int nbr)
{
	unsigned int	i;

	i = 0;
	while (begin_list)
	{
		if (i++ == nbr)
			return (begin_list);
		begin_list = begin_list->next;
	}
	return (NULL);
}
void	ft_list_reverse(t_list **begin_list)
{
	t_list	*prev;
	t_list	*cr;
	t_list	*next;

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

