#include "libft.h"

int	ft_strequ(char const *s1, char const *s2)
{
	int	a;

	a = 0;
	if (s1 == NULL || s2 == NULL)
		return (0);
	while (s1[a] && s2[a])
	{
		if (s1[a] != s2[a])
			return (0);
		a++;
	}
	if (s1[a] != s2[a])
		return (0);
	return (1);
}
