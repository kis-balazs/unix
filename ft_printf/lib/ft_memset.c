/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkis <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/05 16:23:08 by bkis              #+#    #+#             */
/*   Updated: 2017/07/05 16:23:09 by bkis             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	*ft_memset(void *dest, int c, size_t n)
{
	size_t			i;
	unsigned char	*dest1;
	unsigned char	c1;

	i = 0;
	dest1 = dest;
	c1 = c;
	while (i < n)
		dest1[i++] = c1;
	return (dest);
}
