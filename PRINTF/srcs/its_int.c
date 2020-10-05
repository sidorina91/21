#include "ft_printf.h"

void	int_checker(t_struct *prms)
{
	if (prms->negative && prms->zero)
		prms->n_printed_here += write(1, "-", 1);
	if (prms->plus && !prms->negative && prms->zero)
		prms->n_printed_here += write(1, "+", 1);
	if (prms->space && !prms->negative && prms->zero)
		prms->n_printed_here += write(1, " ", 1);
}

int		int_printer_2(t_struct *prms, char *s)
{
	if ((!prms->width && prms->dot && prms->zero_arg
	&& prms->prec_zero) || (!prms->width
	&& prms->dot && !prms->prec && !prms->prec_zero
	&& prms->zero_arg))
		return (0);
	if (prms->width && prms->dot && prms->zero_arg
	&& !prms->prec)
		if (prms->plus)
			write(1, "", 0);
		else
			prms->n_printed_here += write(1, " ", 1);
	else
		prms->n_printed_here += write(1, s, prms->len_before);
	if (prms->width && prms->minus)
		while (prms->n_printed_here < prms->width)
			prms->n_printed_here += write(1, " ", 1);
	return (1);
}

void	int_printer(t_struct *prms, char *s, int indent)
{
	int_checker(prms);
	if (prms->width > prms->len_before)
		indent = prms->width - prms->len_before;
	if (prms->negative || prms->plus || prms->space)
		indent--;
	if (prms->zero_arg && prms->plus && prms->dot
	&& prms->width && !prms->prec)
		indent++;
	if (prms->width > prms->len_before && !prms->minus)
	{
		while (indent--)
		{
			prms->n_printed_here += (prms->zero
					&& !prms->prec) ? write(1, "0", 1)
					: write(1, " ", 1);
		}
	}
	if (prms->negative && !prms->zero)
		prms->n_printed_here += write(1, "-", 1);
	if (prms->plus && !prms->negative && !prms->zero)
		prms->n_printed_here += write(1, "+", 1);
	if (prms->space && !prms->negative && !prms->zero)
		prms->n_printed_here += write(1, " ", 1);
	int_printer_2(prms, s);
}

void	int_from_fmt(t_struct *prms, intmax_t num, int i)
{
	char	*s;
	int		indent;

	indent = 0;
	prms->len_before = num_len(num, 10);
	s = itoa_base(prms, num, 10);
	s = int_ovrflw_check(num, s);
	if (prms->dot)
		prms->zero = 0;
	if ((num == 0) && (prms->len_before == 1))
		prms->zero_arg++;
	if (prms->prec && prms->prec
	> prms->len_before && !prms->negative)
		s = int_with_prec(prms, s, i);
	else if (prms->prec && prms->prec
	> prms->len_before && prms->negative)
		s = int_with_prec(prms, s, i);
	prms->len_before = ft_strlen(s);
	int_printer(prms, s, indent);
	prms->n_printed += prms->n_printed_here;
	if (num != LLONG_MAX && num != LLONG_MIN)
		free(s);
	struct_bzeroer(prms, 0);
}

void	its_int(va_list args, t_struct *prms)
{
	intmax_t num;

	num = 0;
	if (prms->len == 0)
		num = (int)va_arg(args, int);
	if (prms->len == SHORTSHORT)
		num = (signed char)va_arg(args, int);
	if (prms->len == SHORT)
		num = (short int)va_arg(args, int);
	if (prms->len == LONG)
		num = (long int)va_arg(args, long int);
	if (prms->len == LONGLONG)
		num = (long long int)va_arg(args, long long int);
	if (prms->len == SIZET)
		num = (size_t)va_arg(args, size_t);
	if (prms->len == _UINT_MAX)
		num = (intmax_t)va_arg(args, intmax_t);
	if (prms->dot > 1 && prms->prec)
	{
		prms->dot = 0;
		prms->zero = 0;
		prms->prec = 0;
	}
	int_from_fmt(prms, num, 0);
}
