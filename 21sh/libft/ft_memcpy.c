/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkis <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/07 13:58:24 by bkis              #+#    #+#             */
/*   Updated: 2017/07/07 13:58:24 by bkis             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Includes/libft.h"

void			*ft_memcpy(void *s1, const void *s2, size_t n)
{
	size_t		i;
	char		*dest2;
	const char	*src2;

	i = 0;
	dest2 = s1;
	src2 = s2;
	while (n > i)
	{
		dest2[i] = src2[i];
		i++;
	}
	return (dest2);
}
