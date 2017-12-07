/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkis <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/15 16:47:07 by bkis              #+#    #+#             */
/*   Updated: 2017/05/15 16:47:08 by bkis             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned long	index;
	char			*b2;
	unsigned char	c2;

	if (len)
	{
		c2 = (unsigned char)c;
		b2 = (char *)b;
		index = 0;
		while (index < len)
		{
			b2[index] = c2;
			index++;
		}
	}
	return (b);
}
