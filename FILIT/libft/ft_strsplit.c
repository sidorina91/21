#include "libft.h"

static int		wordcounter(const char *str, char c)
{
	int flag;
	int count;

	flag = 1;
	count = 0;
	while (*str)
	{
		if (flag && *str != c)
		{
			count++;
			flag = 0;
		}
		else if (!flag && *str == c)
			flag = 1;
		str++;
	}
	return (count);
}

static void		clear(char **res, int cnt)
{
	while (cnt >= 0)
	{
		free(res[cnt]);
		cnt--;
	}
	free(res);
}

static int		createstr(char **res, int index, const char *str, char c)
{
	int len;
	int i;

	len = 0;
	i = 0;
	while (str[i] != c)
	{
		len++;
		i++;
	}
	i = 0;
	if ((res[index] = (char*)malloc(sizeof(char) * (len + 1))))
	{
		while (i < len)
		{
			res[index][i] = str[i];
			i++;
		}
		res[index][i] = '\0';
		return (1);
	}
	return (0);
}

static void		fill(char **res, const char *s, char c, int cnt)
{
	int flag;
	int i;

	flag = 0;
	i = 0;
	while (i < cnt)
	{
		if (!flag && *s != c)
		{
			flag = 1;
			if (!createstr(res, i, s, c))
			{
				clear(res, i);
				break ;
			}
			i++;
		}
		else if (flag && *s == c)
			flag = 0;
		s++;
	}
}

char			**ft_strsplit(const char *s, char c)
{
	char	**result;
	int		wordcnt;

	result = NULL;
	if (s)
	{
		wordcnt = wordcounter(s, c);
		if ((result = (char**)malloc(sizeof(char*) * (wordcnt + 1))))
		{
			result[wordcnt] = NULL;
			fill(result, s, c, wordcnt);
		}
	}
	return (result);
}
