#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*dest;
	int		i;

	i = 0;
	if ((dest = (char*)malloc(sizeof(char) * ft_strlen(s1) + 1)))
	{
		while (s1[i] != '\0')
		{
			dest[i] = (char)s1[i];
			i++;
		}
		dest[i] = '\0';
	}
	return (dest);
}
