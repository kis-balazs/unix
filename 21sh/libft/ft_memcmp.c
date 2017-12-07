/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkis <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/07 13:58:17 by bkis              #+#    #+#             */
/*   Updated: 2017/07/07 13:58:18 by bkis             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Includes/libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t num)
{
	const unsigned char	*str1;
	const unsigned char	*str2;

	if (s1 == s2 || num == 0)
		return (0);
	str1 = (const unsigned char *)s1;
	str2 = (const unsigned char *)s2;
	while (num--)
	{
		if (*str1 != *str2)
			return (*str1 - *str2);
		if (num)
		{
			str1++;
			str2++;
		}
	}
	return (0);
}
