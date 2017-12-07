/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkis <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/15 16:46:36 by bkis              #+#    #+#             */
/*   Updated: 2017/05/15 16:46:38 by bkis             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, void const *src, size_t n)
{
	char		*tmp_d;
	char const	*tmp_s;
	int			index;

	index = 0;
	tmp_d = (char *)dst;
	tmp_s = (char const *)src;
	while (n)
	{
		tmp_d[index] = tmp_s[index];
		n--;
		index++;
	}
	return (dst);
}
