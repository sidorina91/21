#include "ft_printf.h"

int		len_recalcer(char *s, int i)
{
	int new_len;

	new_len = 0;
	while (s[i])
	{
		if ((s[i] >= 1 && s[i] <= 32) || s[i] == 127)
			new_len += 2;
		else
			new_len++;
		i++;
	}
	return (new_len);
}

void	str_refresher(char *s, char *s_nonpr, int i, int j)
{
	while (s[i])
	{
		if ((s[i] >= 1 && s[i] <= 32) || s[i] == 127)
		{
			s_nonpr[j++] = '^';
			if (s[i] == 0)
				s_nonpr[j] = '@';
			else if (s[i] == 127)
				s_nonpr[j] = '?';
			else
				s_nonpr[j] = 64 + s[i];
		}
		else
			s_nonpr[j] = s[i];
		i++;
		j++;
	}
	s_nonpr[j] = '\0';
}

void	nonprint_creator(va_list args, t_struct *prms)
{
	char	*s;
	char	*s_nonpr;
	int		new_len;

	if (!(s = (char *)va_arg(args, char *)))
		s = "(null)";
	prms->len_before = ft_strlen(s);
	new_len = len_recalcer(s, 0);
	if (!(s_nonpr = (char *)malloc(sizeof(*s_nonpr)
			* ((new_len) + 1))))
		s_nonpr = "(null)";
	str_refresher(s, s_nonpr, 0, 0);
	prms->len_before = new_len;
	str_printer(prms, s_nonpr);
	free(s_nonpr);
	struct_bzeroer(prms, 0);
}
