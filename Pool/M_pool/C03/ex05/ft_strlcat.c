/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Noctis <Noctis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 18:11:25 by aakritah          #+#    #+#             */
/*   Updated: 2024/09/06 05:44:32 by Noctis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>


unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
    unsigned int i;
    unsigned int s1;
    unsigned int s2;

    s1 = 0;
    while(src[s1])
        s1++;
        
    s2=0;
    while (dest[s2])
        s2++;
        
    if(size <= s2)
		return (s1 + size);
    
	i = 0;
	while(src[i])
    {
		dest[s2+i]=src[i];
		i++;
    }
	dest[s2+i] = '\0';
	return (s1 + s2);


}




// unsigned int ft_strlcat(char *dest, char *src, unsigned int size)
// {
//     unsigned int i;
//     unsigned int s1;
//     unsigned int s2;

//     s1=0;
//     while(src[s1])
//         s1++;
    
//     s2=0;
//     while(dest[s2])
//         s2++;
    
//     if(size <= s2)
//         return (size + s1);
    
//     i = 0;
//     while(src[i] && s2+i<size-1)
//     {
//         dest[s2+i] == src[i];
//         i++;
//     }
//     dest[s2+i] == '\0';
    
//     return (s1+s2);
// }




// unsigned int ft_strlcat(char *dest, char *src, unsigned int size)
// {
//     unsigned int i = 0;
//     unsigned int j = 0;
//     unsigned int dest_len = 0;
//     unsigned int src_len = 0;

//     // Calculate the length of dest
//     while (dest[dest_len])
//         dest_len++;

//     // Calculate the length of src
//     while (src[src_len])
//         src_len++;

//     // If size is less than or equal to the length of dest, return size + src_len
//     if (size <= dest_len)
//         return (size + src_len);

//     // Append src to dest
//     i = dest_len;
//     while (src[j] && i < size - 1)
//     {
//         dest[i] = src[j];
//         i++;
//         j++;
//     }

//     // Null-terminate dest
//     dest[i] = '\0';

//     // Return the total length of the string that would have been created
//     return (dest_len + src_len);
// }
