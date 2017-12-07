/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkis <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/25 18:43:23 by bkis              #+#    #+#             */
/*   Updated: 2017/01/25 19:20:17 by bkis             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*b_char;

	if (b == NULL || len <= 0)
		return (b);
	b_char = (unsigned char*)b;
	while (len > 0)
	{
		*b_char = (unsigned char)c;
		b_char++;
		len--;
	}
	return (b);
}
