#include "libft.h"

char	*ft_strcpy(char *dest, char *src)
{
	int count_src;

	count_src = 0;
	while (src[count_src] != '\0')
	{
		dest[count_src] = src[count_src];
		count_src++;
	}
	dest[count_src] = '\0';
	return (dest);
}
