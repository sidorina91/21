#include "ft_printf.h"

void	float_printer_2(t_struct *prms)
{
	int	i;

	i = 0;
	ft_putstr(prms->f_before);
	prms->n_printed_here += prms->len_before;
	if ((prms->hash || prms->prec) && !ft_isalpha(prms->f_before[0]))
		prms->n_printed_here += write(1, ".", 1);
	if (prms->prec)
	{
		while (i++ < prms->prec - prms->len_after)
			prms->n_printed_here += write(1, "0", 1);
		ft_putstr(prms->f_after);
		prms->n_printed_here += prms->len_after;
	}
	if (prms->width && prms->minus)
		while (prms->n_printed_here < prms->width)
			prms->n_printed_here += write(1, " ", 1);
	prms->n_printed += prms->n_printed_here;
}

void	float_printer(t_struct *prms)
{
	int len;
	int	indent;

	indent = 0;
	len = prms->len_before + prms->len_after;
	if ((prms->hash || prms->prec) && !ft_isalpha(prms->f_before[0]))
		len++;
	if (prms->width > len)
		indent = prms->width - len;
	if (prms->negative || prms->plus || prms->space)
		indent--;
	if (prms->width > len && !prms->minus && !prms->zero)
		while (indent--)
			prms->n_printed_here += write(1, " ", 1);
	if (prms->space && !prms->negative)
		prms->n_printed_here += write(1, " ", 1);
	if (prms->negative)
		prms->n_printed_here += write(1, "-", 1);
	if (prms->plus && !prms->negative)
		prms->n_printed_here += write(1, "+", 1);
	if (prms->width > len && !prms->minus && prms->zero)
		while (indent--)
			prms->n_printed_here += write(1, "0", 1);
	float_printer_2(prms);
}

void	f_incrementer(t_struct *prms)
{
	long double fbefore;

	fbefore = ft_atof(prms->f_before);
	fbefore++;
	prms->f_before = itoa_base_uint((uintmax_t)fbefore, 10);
}

int		is_odd(char c)
{
	return ((c - '0') % 2);
}

int		is_inf_nan(t_struct *prms, long double num)
{
	prms->len_before = 3;
	if (num == (1.0 / 0.0) || num == -(1.0 / 0.0))
	{
		if (num == -(1.0 / 0.0))
			prms->negative = 1;
		prms->f_before = "inf";
		float_printer(prms);
		return (1);
	}
	return (0);
}
