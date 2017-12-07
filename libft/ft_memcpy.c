/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkis <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/10 16:40:52 by bkis              #+#    #+#             */
/*   Updated: 2017/01/10 16:52:40 by bkis             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	counter;
	char	*str_dst;
	char	*str_src;

	if (!dst || !src)
		return (NULL);
	counter = 0;
	str_dst = (char *)dst;
	str_src = (char *)src;
	while (counter < n)
	{
		str_dst[counter] = str_src[counter];
		counter++;
	}
	return ((void*)dst);
}
