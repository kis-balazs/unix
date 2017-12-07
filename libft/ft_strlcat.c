/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkis <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/10 16:44:03 by bkis              #+#    #+#             */
/*   Updated: 2017/01/10 16:57:28 by bkis             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	len1;
	size_t	len2;
	size_t	i;

	if (dst == NULL || src == NULL)
		return (0);
	len1 = ft_strlen(dst);
	len2 = ft_strlen(src);
	if (size < len1)
		return (len2 + size);
	i = 0;
	while (len1 + i < size - 1 && i < len2)
	{
		dst[len1 + i] = src[i];
		i++;
	}
	dst[len1 + i] = '\0';
	return (len1 + len2);
}
