/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkis <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/07 13:58:09 by bkis              #+#    #+#             */
/*   Updated: 2017/07/07 13:58:10 by bkis             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Includes/libft.h"

void	*ft_memchr(const void *str, int c, size_t n)
{
	size_t			i;
	unsigned char	*s;

	s = (unsigned char*)str;
	i = 0;
	while (i < n)
	{
		if (s	[i] == (unsigned char)c)
			return ((void*)(s + i));
		i++;
	}
	return (NULL);
}
