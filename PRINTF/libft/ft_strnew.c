#include "libft.h"

char	*ft_strnew(size_t size)
{
	char *res;

	if (size + 1 == 0)
		return (NULL);
	if ((res = (char*)malloc(sizeof(char) * (size + 1))))
	{
		ft_bzero(res, size + 1);
		return (res);
	}
	return (NULL);
}
