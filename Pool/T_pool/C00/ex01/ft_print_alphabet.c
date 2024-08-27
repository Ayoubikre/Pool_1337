#include <unistd.h>

void	ft_print_alphabet(void)
{
	int	i;

	i = 0;
	while (i < 26)
	{
		write(1, &(char){'a' + i}, 1);
		i++;
	}
}
