/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printunlong.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkis <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/07 13:59:26 by bkis              #+#    #+#             */
/*   Updated: 2017/07/07 13:59:27 by bkis             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Includes/libft.h"

void			ft_printunlong(unsigned long long ll)
{
	size_t	ret;

	ret = 1;
	if (ll >= 10)
	{
		ft_printunlong(ll / 10);
		ft_printunlong(ll % 10);
	}
	else
		ft_putchar(ll + '0');
}
