
#include <unistd.h>

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	i;
	unsigned int	s1;
	unsigned int	s2;
	unsigned int	h;

	s1 = 0;
	s2 = 0;
	h = 0;


	while (src[s1])
		s1++;
	while (dest[s2])
		s2++;


	h = s2;


	if (size <= s2)
		return (size + s1);

        
	i = 0;
	while (src[i] && s2 < size - 1)
	{
		dest[s2] = src[i];
		i++;
		s2++;
	}






	dest[s2] = '\0';
	return (s1 + h);
}
