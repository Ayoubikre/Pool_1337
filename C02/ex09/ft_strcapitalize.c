/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Noctis <Noctis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 20:50:23 by Noctis            #+#    #+#             */
/*   Updated: 2024/09/03 01:38:05 by Noctis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcapitalize(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if ((((9 < str[i - 1] && str[i - 1] < 13) || str[i - 1] == ' ')
				|| i == 0) && 'a' <= str[i] && str[i] <= 'z')
			str[i] -= 32;
		else
		{
			if (!(('0' <= str[i - 1] && str[i - 1] <= '9') || ('a' <= str[i - 1]
						&& str[i - 1] <= 'z') || ('A' <= str[i - 1] && str[i
							- 1] <= 'Z')))
			{
				if ('a' <= str[i] && str[i] <= 'z')
					str[i] -= 32;
			}
			else if ('A' <= str[i] && str[i] <= 'Z')
				str[i] += 32;
		}
		i++;
	}
	return (str);
}
