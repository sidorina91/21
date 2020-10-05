#include "ft_printf.h"

char	*hex_with_prec(t_struct *prms, char *s, int i)
{
	char	*s_prec;
	int		j;

	j = 0;
	if (!(s_prec = (char *)malloc(sizeof(char)
			* (prms->prec + 1))))
		s_prec = NULL;
	while (i < (prms->prec - prms->len_before))
	{
		s_prec[i] = '0';
		i++;
	}
	while (s[j])
	{
		s_prec[i] = s[j];
		i++;
		j++;
	}
	s_prec[i] = '\0';
	free(s);
	return (s_prec);
}

char	*hex_hash(t_struct *params, char *s)
{
	char	*s_hash;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!(s_hash = (char *)malloc(sizeof(char)
			* (params->len_before + 3))))
		s_hash = NULL;
	s_hash[i++] = '0';
	if (params->small_hex)
		s_hash[i++] = 'x';
	else
		s_hash[i++] = 'X';
	while (s[j])
	{
		s_hash[i] = s[j];
		i++;
		j++;
	}
	s_hash[i] = '\0';
	free(s);
	return (s_hash);
}

void	hex_hash_check(t_struct *prms, int num)
{
	if ((num == 0) && (prms->len_before == 1))
		prms->zero_arg++;
	if (!prms->width && prms->hash
	&& prms->dot && prms->zero_arg)
		prms->hash_case++;
	if (prms->hash && prms->width
	&& !prms->prec && prms->zero_arg)
		prms->hash_case++;
	if (prms->hash && prms->dot
	&& !prms->prec && !prms->prec_zero)
		prms->hash = 0;
	if (prms->zero_arg)
		prms->hash = 0;
}
