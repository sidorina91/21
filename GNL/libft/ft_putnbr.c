#include "libft.h"

void	ft_putnbr(int nb)
{
	long chislo;

	chislo = (long)(nb);
	if (chislo < 0)
	{
		ft_putchar('-');
		chislo = -1 * chislo;
	}
	if (chislo <= 9 && chislo > 0)
		ft_putchar(chislo + 48);
	else if (chislo == 0)
		ft_putchar('0');
	else
	{
		ft_putnbr(chislo / 10);
		ft_putchar((chislo % 10) + 48);
	}
}
