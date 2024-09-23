/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Noctis <Noctis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 03:00:14 by Noctis            #+#    #+#             */
/*   Updated: 2024/09/03 03:18:55 by Noctis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	i;
	unsigned int	s1;
	unsigned int	s2;

	s1 = 0;
	while (dest[s1])
		s1++;
	s2 = 0;
	while (src[s2])
		s2++;
	if (size <= s1)
		return (size + s2);
	i = 0;
	while (src[i] && (s1 + i) < (size - 1))
	{
		dest[s1 + i] = src[i];
		i++;
	}
	dest[s1 + i] = '\0';
	return (s1 + s2);
}
