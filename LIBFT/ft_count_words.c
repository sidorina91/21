/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_words.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alytle <alytle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 11:10:53 by darugula          #+#    #+#             */
/*   Updated: 2019/09/18 21:27:21 by alytle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_count_words(const char *str, const char whitespaces[])
{
	int	i;
	int	j;

	i = 0;
	j = 1;
	while (*str != 0)
	{
		if (ft_contains(whitespaces, *str) == 0)
		{
			if (j == 1)
			{
				++i;
			}
			j = 0;
		}
		if (ft_contains(whitespaces, *str) == 1)
		{
			j = 1;
		}
		++str;
		continue;
	}
	return (i);
}
