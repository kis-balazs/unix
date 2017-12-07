/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lenghtlong.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkis <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/07 13:55:52 by bkis              #+#    #+#             */
/*   Updated: 2017/07/07 13:55:54 by bkis             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Includes/libft.h"
#define LONG_LONG_MIN 9223372036854775807

int			ft_lenghtlong(long long ll)
{
	size_t	ret;

	ret = 1;
	if (ll == LONG_LONG_MIN)
		return (20);
	if (ll < 0)
	{
		ret++;
		ll *= -1;
	}
	while ((ll /= 10) > 0)
		ret++;
	return (ret);
}
