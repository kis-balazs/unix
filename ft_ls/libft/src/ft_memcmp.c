/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkis <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/11 12:53:28 by bkis              #+#    #+#             */
/*   Updated: 2017/03/11 12:53:28 by bkis             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(void const *s1, void const *s2, size_t n)
{
	unsigned char *cs1;
	unsigned char *cs2;

	if (n == 0)
		return (0);
	cs1 = (unsigned char *)s1;
	cs2 = (unsigned char *)s2;
	while (*cs1 == *cs2)
	{
		n--;
		if (!n)
			return (0);
		cs1++;
		cs2++;
	}
	return (*cs1 - *cs2);
}
