/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_size.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Noctis <Noctis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 02:32:52 by Noctis            #+#    #+#             */
/*   Updated: 2024/09/22 02:09:21 by Noctis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

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

// int	main(void)
// {
// 	int		i;
// 	int		*data;
// 	t_list	*list;
// 	t_list	*ptr;
// 	t_list	*tmp;

// 	list = NULL;
// 	i = 0;
// 	while (i < 16)
// 	{
// 		data = malloc(sizeof(int));
// 		if (data)
// 		{
// 			*data = i;
// 			ft_list_push_front(&list, data);
// 		}
// 		i++;
// 	}
// 	ptr = list;
// 	printf("size = %i\n", ft_list_size(ptr));
// 	while (ptr != NULL)
// 	{
// 		printf("data = %i\n", *(int *)ptr->data);
// 		ptr = ptr->next;
// 	}
// 	ptr = list;
// 	while (ptr)
// 	{
// 		tmp = ptr;
// 		ptr = ptr->next;
// 		free(tmp->data);
// 		free(tmp);
// 	}
// }
