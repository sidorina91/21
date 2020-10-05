#include "ft_printf.h"

void	prec_determer(const char *fmt, t_struct *prms)
{
	if (fmt[prms->i] == '.')
	{
		prms->i++;
		prms->dot++;
	}
	if (ft_isdigit(fmt[prms->i]))
	{
		prms->prec = ft_atoi(&fmt[prms->i]);
		if (fmt[prms->i] == '0')
			prms->prec_zero++;
		prms->i += uint_num_len(prms->prec, 10);
	}
}

void	width_determer(const char *fmt, t_struct *prms)
{
	if (ft_isdigit(fmt[prms->i]))
	{
		prms->width = ft_atoi(&fmt[prms->i]);
		prms->i += uint_num_len(prms->width, 10);
	}
}

void	flag_hooker(const char *fmt, t_struct *prms)
{
	while (ft_strchr("-+ #0", fmt[prms->i]))
	{
		if (fmt[prms->i] == '-')
			prms->minus = 1;
		if (fmt[prms->i] == '+')
			prms->plus = 1;
		if (fmt[prms->i] == ' ')
			prms->space = 1;
		if (fmt[prms->i] == '#')
			prms->hash = 1;
		if (fmt[prms->i] == '0')
			prms->zero = 1;
		prms->i++;
	}
	if (prms->plus == 1)
		prms->space = 0;
	if (prms->minus == 1)
		prms->zero = 0;
}

void	length_determer(const char *fmt, t_struct *prms)
{
	if (ft_strchr("hlLjz", fmt[prms->i]))
	{
		while (ft_strchr("hlLjz", fmt[prms->i]))
		{
			if (fmt[prms->i] == 'h' && prms->len < SHORT)
				prms->len = SHORT;
			if (fmt[prms->i] == 'h' && fmt[prms->i + 1] == 'h'
				&& prms->len < SHORTSHORT)
				prms->len = SHORTSHORT;
			if (fmt[prms->i] == 'l' && prms->len < LONG)
				prms->len = LONG;
			if (fmt[prms->i] == 'l' && fmt[prms->i + 1] == 'l'
				&& prms->len < LONGLONG)
				prms->len = LONGLONG;
			if (fmt[prms->i] == 'L')
				prms->len = LONGDOUBLE;
			if (fmt[prms->i] == 'z' && prms->len < SIZET)
				prms->len = SIZET;
			if (fmt[prms->i] == 'j' && prms->len < _UINT_MAX)
				prms->len = _UINT_MAX;
			prms->i++;
		}
	}
}

int		modifiers(va_list args, const char *fmt, t_struct *params)
{
	if (args == NULL)
		return (0);
	flag_hooker(fmt, params);
	width_determer(fmt, params);
	length_determer(fmt, params);
	prec_determer(fmt, params);
	return (params->i);
}
