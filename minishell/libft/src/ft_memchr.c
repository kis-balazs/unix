/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkis <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/15 16:46:16 by bkis              #+#    #+#             */
/*   Updated: 2017/05/15 16:46:17 by bkis             ###   ########.fr       */
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
