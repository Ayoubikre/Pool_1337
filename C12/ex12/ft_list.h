/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Noctis <Noctis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 23:11:10 by Noctis            #+#    #+#             */
/*   Updated: 2024/09/23 01:49:04 by Noctis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LIST_H
# define FT_LIST_H

# include <stdio.h>
# include <stdlib.h>

typedef struct s_list
{
	struct s_list	*next;
	void			*data;
}					t_list;

t_list				*ft_create_elem(void *data);
t_list				*ft_list_last(t_list *begin_list);
t_list				*ft_list_push_strs(int size, char **strs);
t_list				*ft_list_at(t_list *begin_list, unsigned int nbr);
t_list				*ft_list_find(t_list *begin_list, void *data_ref,
						int (*cmp)());
void				ft_list_foreach_if(t_list *begin_list, void (*f)(void *),
						void *data_ref, int (*cmp)());
void				ft_list_remove_if(t_list **begin_list, void *data_ref,
						int (*cmp)(), void (*free_fct)(void *));
void				ft_list_push_front(t_list **begin_list, void *data);
void				ft_list_push_back(t_list **begin_list, void *data);
void				ft_list_clear(t_list *begin_list, void (*free_fct)(void *));
void				ft_list_reverse(t_list **begin_list);
void				ft_list_foreach(t_list *begin_list, void (*f)(void *));
void				ft_free(void *data);
void				delete_element(void *element);
int					compare_modulo(void *data, void *data_ref);
int					ft_list_size(t_list *begin_list);

#endif