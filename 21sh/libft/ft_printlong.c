/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printlong.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkis <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/07 13:59:02 by bkis              #+#    #+#             */
/*   Updated: 2017/07/07 13:59:03 by bkis             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Includes/libft.h"

void			ft_printlong(long long ll)
{
	size_t	ret;

	ret = 1;
	if (ll == LONG_LONG_MIN)
	{
		ft_putstr("-9223372036854775808");
		return ;
	}
	if (ll < 0)
	{
		ft_putchar('-');
		ll = -ll;
	}
	if (ll >= 10)
	{
		ft_printlong(ll / 10);
		ft_printlong(ll % 10);
	}
	else
		ft_putchar(ll + '0');
}
