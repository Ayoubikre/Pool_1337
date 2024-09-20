/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Noctis <Noctis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 22:42:54 by Noctis            #+#    #+#             */
/*   Updated: 2024/09/19 23:06:35 by Noctis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_H
# define MAIN_H

# include <stdio.h>
# include <unistd.h>

int		ft_atoi(char *t);
void	ft_calcul(char *t1, char *t2, void (*f)(int, int));
void	ft_putnbr(long nb);
void	ft_remplire(char **t, void (*f[])(int, int));
void	ft_putstr(char *t);
int		ft_strcmp(char *t, char *t2);
void	add(int n1, int n2);
void	sub(int n1, int n2);
void	div(int n1, int n2);
void	multi(int n1, int n2);
void	mod(int n1, int n2);

# define MSG_DIV "Stop : division by zero"
# define MSG_MOD "Stop : modulo by zero"

#endif