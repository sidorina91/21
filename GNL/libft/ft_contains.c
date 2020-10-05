/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_contains.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alytle <alytle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 21:26:18 by alytle            #+#    #+#             */
/*   Updated: 2019/09/18 21:26:38 by alytle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_contains(const char *str, char to_find)
{
	while (*str != 0)
	{
		if (*str == to_find)
		{
			return (1);
		}
		str++;
	}
	return (0);
}