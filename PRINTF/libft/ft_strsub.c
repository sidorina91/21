#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char		*res;
	size_t		i;

	res = NULL;
	if (s)
	{
		i = 0;
		res = ft_strnew(len);
		if (res)
		{
			while (i < len)
			{
				res[i] = s[start + i];
				i++;
			}
		}
	}
	return (res);
}
