#include "ft_printf.h"

int		hex_printer_2(t_struct *prms, char *s)
{
	if ((!prms->width && prms->dot && prms->zero_arg
	&& prms->prec_zero) || (!prms->width && prms->dot
	&& !prms->prec && !prms->prec_zero && prms->zero_arg))
		return (0);
	if (prms->width && prms->dot
		&& prms->zero_arg && !prms->prec)
		prms->n_printed_here += write(1, " ", 1);
	else
		prms->n_printed_here += write(1, s, prms->len_before);
	if (prms->width && prms->minus)
		while (prms->n_printed_here < prms->width)
			prms->n_printed_here += write(1, " ", 1);
	return (1);
}

void	hex_printer(t_struct *params, char *s, int indent)
{
	if (params->width > params->len_before)
		indent = params->width - params->len_before;
	if (params->negative || params->plus || params->space)
		indent--;
	if (params->hash_case_zero)
	{
		params->n_printed_here += (params->small_hex == 1)
				? write(1, "0x", 2)
				: write(1, "0X", 2);
		indent -= 2;
	}
	if (params->width > params->len_before && !params->minus)
	{
		while (indent--)
		{
			params->n_printed_here += (params->zero
					&& !params->prec) ? write(1, "0", 1)
					: write(1, " ", 1);
		}
	}
	if (params->space && !params->negative)
		params->n_printed_here += write(1, " ", 1);
	hex_printer_2(params, s);
}

void	hex_from_fmt_2(t_struct *prms, char *s, int indent)
{
	if (prms->hash)
	{
		s = hex_hash(prms, s);
		prms->hash = 0;
	}
	prms->len_before = ft_strlen(s);
	if (prms->plus)
		prms->plus = 0;
	if (prms->space)
		prms->space = 0;
	hex_printer(prms, s, indent);
	prms->n_printed += prms->n_printed_here;
	free(s);
	struct_bzeroer(prms, 0);
}

void	hex_from_fmt(t_struct *prms, uintmax_t num, int i)
{
	char	*s;
	int		indent;

	indent = 0;
	prms->len_before = uint_num_len(num, 16);
	s = (prms->small_hex == 1)
		? itoa_base_uint(num, 16)
		: itoa_base_to_up(num, 16);
	hex_hash_check(prms, num);
	if (prms->prec > prms->len_before)
		s = hex_with_prec(prms, s, i);
	if (prms->hash && prms->zero
		&& prms->width && !prms->prec)
	{
		prms->hash_case_zero++;
		prms->hash = 0;
	}
	hex_from_fmt_2(prms, s, indent);
}

void	its_hex(va_list args, t_struct *params, char spec)
{
	uintmax_t num;

	num = 0;
	if (!params->len)
		num = va_arg(args, unsigned int);
	if (params->len == SHORTSHORT)
		num = (unsigned char)va_arg(args, unsigned int);
	if (params->len == SHORT)
		num = (unsigned short)va_arg(args, unsigned int);
	if (params->len == LONG)
		num = (unsigned long)va_arg(args, unsigned long);
	if (params->len == LONGLONG)
		num = (unsigned long long)va_arg(args,
				unsigned long long);
	if (params->len == SIZET)
		num = (size_t)va_arg(args, size_t);
	if (params->len == _UINT_MAX)
		num = (uintmax_t)va_arg(args, uintmax_t);
	params->small_hex = (spec == 'x') ? 1 : 0;
	hex_from_fmt(params, num, 0);
}
