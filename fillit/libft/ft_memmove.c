/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkis <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/25 18:43:16 by bkis              #+#    #+#             */
/*   Updated: 2017/01/25 19:20:07 by bkis             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*s;

	s = (unsigned char*)malloc(sizeof(s) * len);
	if (s == NULL)
		return (dst);
	ft_memcpy(s, src, len);
	ft_memcpy(dst, s, len);
	free(s);
	return (dst);
}
