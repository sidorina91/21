#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*res;
	int		i;

	i = 0;
	res = NULL;
	if (s && f)
	{
		while (s[i])
			i++;
		res = (char *)malloc(i + 1);
		if (!res)
			return (NULL);
		i = 0;
		while (s[i])
		{
			res[i] = f(s[i]);
			i++;
		}
		res[i] = '\0';
	}
	return (res);
}
