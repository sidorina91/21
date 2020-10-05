#include "libft.h"

int	ft_positionchar(const char *str, char c)
{
	int position;

	if (str)
	{
		position = 0;
		while (str[position] != '\0')
		{
			if (str[position] == c)
				return (position);
			position++;
		}
		return (-1);
	}
	return (-1);
}
