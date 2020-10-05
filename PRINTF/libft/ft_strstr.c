#include "libft.h"

char	*ft_strstr(const char *strm, const char *needle)
{
	unsigned int	i;
	unsigned int	j;

	if (!*needle)
		return ((char *)strm);
	i = 0;
	while (strm[i] != '\0')
	{
		if (strm[i] == needle[0])
		{
			j = 1;
			while (needle[j] != '\0' && strm[i + j] == needle[j])
				j++;
			if (needle[j] == '\0')
				return ((char *)&strm[i]);
		}
		i++;
	}
	return (0);
}
