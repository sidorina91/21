#include "libft.h"

int		ft_atoi(const char *str)
{
	unsigned long	r;
	int				n;

	n = 1;
	r = 0;
	while (*str && (*str == ' ' || *str == '\n' || *str == '\t' ||
		*str == '\v' || *str == '\f' || *str == '\r'))
		str++;
	if (*str == '-')
		n = -1;
	if (*str == '-' || *str == '+')
		++str;
	while (*str && *str >= '0' && *str <= '9')
	{
		r = r * 10 + (unsigned long)(*str - 48);
		++str;
	}
	if (r > 9223372036854775807)
		return (n == -1 ? 0 : -1);
	return ((int)r * n);
}
