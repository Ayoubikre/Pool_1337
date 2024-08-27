#include <unistd.h>

void	ft_print_reverse_alphabet(void)
{
	int	i;

	i = 0;
	while (i < 26)
	{
		write(1, &(char){'z' - i}, 1);
		i++;
	}
}
