/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkis <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/25 18:42:01 by bkis              #+#    #+#             */
/*   Updated: 2017/01/25 19:16:31 by bkis             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static inline int	ft_len(int n)
{
	int len;

	len = 0;
	if (n == 0)
		return (1);
	if (n < 0)
		len++;
	while (n != 0)
	{
		n = n / 10;
		len++;
	}
	return (len);
}

char				*ft_itoa(int n)
{
	char	*str;
	long	nb;
	int		len;

	nb = n;
	len = ft_len(n);
	str = ft_strnew(len);
	if (!str)
		return (NULL);
	if (nb < 0)
	{
		nb = -nb;
		str[0] = '-';
	}
	str[--len] = (nb % 10 + '0');
	nb /= 10;
	while (nb > 0)
	{
		str[--len] = (nb % 10 + '0');
		nb /= 10;
	}
	return (str);
}
