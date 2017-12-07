/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkis <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/10 17:56:11 by bkis              #+#    #+#             */
/*   Updated: 2017/01/10 17:59:21 by bkis             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char *s;

	s = (unsigned char*)malloc(sizeof(s) * len);
	if (s == NULL)
		return (dst);
	ft_memcpy(s, src, len);
	ft_memcpy(dst, s, len);
	free(s);
	return (dst);
}
