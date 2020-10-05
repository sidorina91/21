#include "libft.h"

static int		digit_len(unsigned int nbr)
{
	int i;

	i = 0;
	if (nbr == 0)
		return (1);
	while (nbr > 0)
	{
		nbr = nbr / 10;
		i++;
	}
	return (i);
}

char			*ft_itoa(int nbr)
{
	int				i;
	char			*str;
	int				diglen;
	unsigned int	tmp;

	tmp = (nbr < 0 ? (unsigned int)(nbr * -1) : (unsigned int)(nbr));
	diglen = digit_len(tmp);
	str = (char*)malloc(diglen + 1 + (nbr < 0 ? 1 : 0));
	if (!str)
		return (NULL);
	i = 0;
	if (nbr == 0)
		str[0] = '0';
	while (tmp > 0)
	{
		str[diglen - i + (nbr < 0 ? 1 : 0) - 1] = (char)(tmp % 10) + '0';
		tmp = tmp / 10;
		i++;
	}
	if ((nbr < 0 ? 1 : 0))
		str[0] = '-';
	str[diglen + (nbr < 0 ? 1 : 0)] = '\0';
	return (str);
}
