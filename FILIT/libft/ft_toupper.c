#include "libft.h"

int		ft_toupper(int c)
{
	if (c <= 'z' && c >= 'a')
	{
		return (c - 'a' + 'A');
	}
	return (c);
}
