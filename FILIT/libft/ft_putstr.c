#include "libft.h"

void	ft_putstr(const char *str)
{
	int i;

	if (str)
	{
		i = 0;
		while (str[i])
		{
			ft_putchar(str[i]);
			i++;
		}
	}
}
