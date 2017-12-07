/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkis <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/11 12:47:46 by bkis              #+#    #+#             */
/*   Updated: 2017/03/11 12:47:47 by bkis             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_isspace(int c)
{
	int ret;

	ret = 0;
	if (c == '\t' || c == '\n' || c == ' ' || c == '\v' || c == '\f' \
			|| c == '\r')
		ret = 1;
	return (ret);
}

int				ft_atoi(char const *s)
{
	int ret;
	int i;
	int neg;

	i = 0;
	ret = 0;
	neg = 1;
	while (ft_isspace(s[i]))
		i++;
	if (s[i] == '-' && ft_isdigit(s[i + 1]))
	{
		i++;
		neg = -1;
	}
	else if ((s[i] == '+') && ft_isdigit(s[i + 1]))
		i++;
	while (ft_isdigit(s[i]))
	{
		ret = ret * 10;
		ret = ret + (s[i] - '0');
		i++;
	}
	return (ret * neg);
}
