/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alytle <alytle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 21:27:33 by alytle            #+#    #+#             */
/*   Updated: 2019/09/18 21:27:42 by alytle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	*ft_free_array(char **r, int n)
{
	while (n-- > 0)
	{
		free(r[n]);
	}
	return (NULL);
}

char		**ft_split(char **r, const char *str, int count, const char *sep)
{
	int		i;
	char	*dst;

	i = 0;
	while (i < count)
	{
		dst = malloc((ft_strlen(str) + 1) * sizeof(char));
		if (dst == NULL)
			return (ft_free_array(r, i));
		r[i++] = dst;
		while (*str != 0 && ft_contains(sep, *str) == 1 && ++str)
		{
		}
		if (*str == 0)
		{
			*dst = 0;
			continue;
		}
		while (*str != 0 && ft_contains(sep, *str) == 0)
		{
			*dst++ = *str++;
		}
		*dst = 0;
	}
	return (r);
}
