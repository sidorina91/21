#include "ft_printf.h"

void	round_upper(long double num, t_struct *prms, int i)
{
	if ((num > 0.5)
	|| (num == 0.5 && is_odd(prms->f_after[prms->len_after])))
	{
		if (i)
		{
			if (prms->f_after[--i] != '9')
				prms->f_after[i]++;
			else
			{
				while (prms->f_after[i] == '9' && i >= 0)
					prms->f_after[i--] = '0';
				(i >= 0) ? prms->f_after[i]++
				: f_incrementer(prms);
			}
		}
		else
			f_incrementer(prms);
	}
}

void	decimal_determer(long double num, t_struct *prms)
{
	int		i;
	char	*str;

	i = 0;
	str = prms->f_after;
	if (!(prms->f_after = (char*)malloc(sizeof(str) * prms->prec + 1)))
		exit(1);
	while (i < prms->prec)
	{
		num *= (long double)10;
		prms->f_after[i] = (int)(num) + '0';
		num -= (int)num;
		prms->len_after++;
		i++;
	}
	prms->f_after[i] = '\0';
	round_upper(num, prms, i);
	prms->len_before = ft_strlen(prms->f_before);
}

char	*int_determer(long double num, int end)
{
	int			i;
	int			len;
	char		*str;
	char		*ptr;
	long double temp;

	i = 0;
	len = float_num_len(num);
	if (!(str = (char*)malloc(sizeof(str) * len + end)))
		exit(1);
	ptr = str;
	while (len)
	{
		temp = num;
		while (i++ < (len - 1))
			temp /= 10;
		*ptr++ = (int)temp + '0';
		temp = (int)temp;
		while (i-- > 1)
			temp *= 10;
		num -= temp;
		len--;
	}
	*ptr = '\0';
	return (str);
}

void	float_determer(long double num, t_struct *prms)
{
	int			len;
	long double	temp;
	long double	f_decimal;
	char		*str;

	temp = num * to_power(10, prms->prec);
	str = int_determer(temp, 1);
	temp -= ft_atof(str);
	len = ft_strlen(str);
	if (temp > 0.5 || (temp == 0.5 && is_odd(str[len - 1])))
		num += (0.5 / to_power(10, prms->prec));
	free(str);
	prms->f_before = int_determer(num, 2);
	f_decimal = num - ft_atof(prms->f_before);
	decimal_determer(f_decimal, prms);
}

void	its_float(va_list args, t_struct *params)
{
	long double num;

	if (params->len == LONG)
		num = (double)va_arg(args, double);
	if (params->len == LONGDOUBLE)
		num = (long double)va_arg(args, long double);
	if (params->len == 0)
		num = (double)va_arg(args, double);
	if (is_inf_nan(params, num))
	{
		params->hash = 0;
		params->zero = 0;
		return ;
	}
	if (!params->prec && !params->prec_zero)
		params->prec = 6;
	if (num < 0)
	{
		params->negative++;
		num *= -1;
	}
	float_determer(num, params);
	float_printer(params);
	free(params->f_before);
	free(params->f_after);
}
