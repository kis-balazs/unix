/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkis <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/11 12:49:45 by bkis              #+#    #+#             */
/*   Updated: 2017/03/11 12:49:54 by bkis             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		get_ndigits(int num)
{
	int c;

	c = 0;
	if (num == 0)
		return (1);
	while (num)
	{
		num = num / 10;
		c++;
	}
	return (c);
}

char			*ft_itoa(int n)
{
	int		digits;
	int		sign;
	char	*ret;

	sign = (n < 0) ? 1 : 0;
	digits = get_ndigits(n);
	if (!(ret = ft_strnew(digits + sign)))
		return (ret);
	if (sign)
		ret[0] = '-';
	else if (n > 0)
		digits--;
	else
		ret[0] = '0';
	while (n)
	{
		if (n > 0)
			ret[digits] = '0' + (n % 10);
		else
			ret[digits] = '0' + -(n % 10);
		n = n / 10;
		digits--;
	}
	return (ret);
}
