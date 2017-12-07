/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkis <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/25 18:42:45 by bkis              #+#    #+#             */
/*   Updated: 2017/01/25 19:19:38 by bkis             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	char	*ptr_dst;
	size_t	i;

	if (dst == NULL || src == NULL)
		return (NULL);
	ptr_dst = dst;
	i = 0;
	while (i < n)
	{
		*(ptr_dst + i) = *((unsigned char *)src + i);
		if (*((unsigned char *)src + i) == (unsigned char)c)
			return (dst + i + 1);
		i++;
	}
	return (NULL);
}
