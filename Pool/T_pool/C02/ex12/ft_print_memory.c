/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Noctis <Noctis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 01:07:25 by Noctis            #+#    #+#             */
/*   Updated: 2024/09/08 05:57:20 by Noctis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>
#include <stdio.h>
#include <unistd.h>

void	ft_addres(void *addr)
{
	char		buffer[18];
	uintptr_t	adr2;
	int			i;
	int			j;
	int			k;

	adr2 = (uintptr_t)addr;
	i = (sizeof(uintptr_t) * 2) - 1;
	j = 0;
	while (i >= 0)
	{
		k = (adr2 >> (i * 4)) & 0xF;
		if (k < 10)
			buffer[j] = '0' + k;
		else
			buffer[j] = 'a' + (k - 10);
		j++;
		i--;
	}
	buffer[j] = '\0';
	i = 0;
	while (i < j)
		write(1, &buffer[i++], 1);
	write(1, ": ", 2);
}

void	ft_p(unsigned char c, int count, int i, int flag)
{
	int	k;

	if (flag == 1)
	{
		while (count < 16)
		{
			write(1, " ", 1);
			count = count + 2;
		}
		while (i++ < 16)
			write(1, "  ", 2);
	}
	else
	{
		k = c / 16;
		if (k < 10)
			write(1, &(char){k + '0'}, 1);
		else
			write(1, &(char){(k - 10) + 'a'}, 1);
		k = c % 16;
		if (k < 10)
			write(1, &(char){k + '0'}, 1);
		else
			write(1, &(char){(k - 10) + 'a'}, 1);
	}
}

void	ft_hexa(char *t, void *addr, unsigned int size)
{
	unsigned int	i;
	int				count;
	uint8_t			*adr2;

	i = 0;
	count = 0;
	adr2 = (uint8_t *)addr;
	while (i < size && i < 16)
	{
		if (adr2[i] < 32 || adr2[i] > 126)
			t[i] = '.';
		else
			t[i] = (char)adr2[i];
		ft_p((unsigned char)adr2[i], 0, 0, 0);
		count++;
		if (count % 2 == 0)
			write(1, " ", 1);
		i++;
	}
	t[i] = '\0';
	ft_p(' ', count, i, 1);
}

void	ft_string(char *addr)
{
	while (*addr)
		write(1, addr++, 1);
	write(1, "\n", 1);
}

void	*ft_print_memory(void *addr, unsigned int size)
{
	char	t[17];

	if (size == 0)
		return (addr);
	ft_addres(addr);
	ft_hexa(t, addr, size);
	ft_string(t);
	if (size > 16)
	{
		size -= 16;
		ft_print_memory(addr + 0x10, size);
	}
	if (size < 16)
		return (addr);
	return (addr);
}

// int main(void)
// {
// 	char	src[0xFF + 10];
// 	int		i;

// 	i = 0;
// 	while (i <= 0xFF)
// 	{
// 		src[i] = i;
// 		i++;
// 	}
// 	src[i] = 0;
// 	i = 0;
// 	while (i < 30)
// 	{
// 		ft_print_memory((void *)src, i);
// 		i++;
// 	}
// 	ft_print_memory((void *)src, 0x101);
// }
