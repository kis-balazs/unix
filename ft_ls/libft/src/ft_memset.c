/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkis <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/11 12:53:52 by bkis              #+#    #+#             */
/*   Updated: 2017/03/11 12:53:53 by bkis             ###   ########.fr       */
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
