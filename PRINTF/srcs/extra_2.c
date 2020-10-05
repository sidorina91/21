#include "ft_printf.h"

void		struct_bzeroer(t_struct *prms, int full)
{
	if (full)
	{
		prms->i = 0;
		prms->n_printed = 0;
	}
	prms->n_printed_here = 0;
	prms->negative = 0;
	prms->minus = 0;
	prms->plus = 0;
	prms->space = 0;
	prms->zero = 0;
	prms->zero_arg = 0;
	prms->hash = 0;
	prms->hash_case = 0;
	prms->hash_case_zero = 0;
	prms->small_hex = 0;
	prms->dot = 0;
	prms->width = 0;
	prms->prec = 0;
	prms->prec_was = 0;
	prms->indent = 0;
	prms->prec_zero = 0;
	prms->len = 0;
	prms->len_before = 0;
	prms->len_after = 0;
}

long double	to_power(long long n, int i)
{
	long long	j;
	long double	res;

	j = 0;
	res = n;
	if (!i)
		return (1);
	while (j++ < (i - 1))
		res *= n;
	return (res);
}

int			float_num_len(long double num)
{
	int	num_len;

	num_len = 0;
	while (num >= 1)
	{
		num /= 10;
		num_len++;
	}
	if (num_len == 0)
		return (1);
	return (num_len);
}

long double	ft_atof(char *str)
{
	long double	num;

	num = 0;
	while (*str)
	{
		num *= 10;
		num += (long double)(*str - '0');
		str++;
	}
	return (num);
}

void		percenter(t_struct *params)
{
	char_printer(params, '%', 0);
	struct_bzeroer(params, 0);
}
