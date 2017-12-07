/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkis <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/07 13:58:43 by bkis              #+#    #+#             */
/*   Updated: 2017/07/07 13:58:43 by bkis             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Includes/libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*tmp;
	size_t			count;

	count = 0;
	tmp = (unsigned char*)s;
	if (n <= 0)
		return (s);
	while (count < n)
	{
		tmp[count] = c;
		count++;
	}
	return (s);
}
