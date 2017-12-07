/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkis <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/07 13:58:04 by bkis              #+#    #+#             */
/*   Updated: 2017/07/07 13:58:05 by bkis             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Includes/libft.h"

void	*ft_memccpy(void *s1, const void *s2, int c, size_t n)
{
	size_t			i;
	unsigned char	*s;
	unsigned char	*d;

	i = 0;
	s = (unsigned char*)s1;
	d = (unsigned char*)s2;
	while (i < n && d[i] != (unsigned char)c)
	{
		s[i] = d[i];
		i++;
	}
	if (i == n)
		return (NULL);
	if (d[i] == (unsigned char)c)
	{
		s[i] = d[i];
		i++;
	}
	return ((void*)(s + i));
}
