/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkis <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/11 12:53:23 by bkis              #+#    #+#             */
/*   Updated: 2017/03/11 12:53:24 by bkis             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(void const *s, int c, size_t len)
{
	unsigned int	index;
	void			*ret;
	unsigned char	cu;
	unsigned char	*si;

	cu = (unsigned char)c;
	si = (unsigned char *)s;
	index = 0;
	while (index < len && si[index] != cu)
		index++;
	if (index == len)
		ret = NULL;
	else
		ret = (void *)(si + index);
	return (ret);
}
