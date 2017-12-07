/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkis <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/11 12:53:15 by bkis              #+#    #+#             */
/*   Updated: 2017/03/11 12:53:16 by bkis             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, void const *src, int c, size_t len)
{
	int					index;
	void				*ret;
	unsigned char		cu;
	unsigned char		*tmp_d;
	unsigned const char *tmp_s;

	cu = (unsigned char)c;
	index = 0;
	tmp_d = (unsigned char *)dest;
	tmp_s = (unsigned char const *)src;
	while (len && tmp_s[index] != cu)
	{
		tmp_d[index] = tmp_s[index];
		len--;
		index++;
	}
	if (tmp_s[index] == cu)
	{
		tmp_d[index] = cu;
		ret = (void *)(tmp_d + (index + 1));
	}
	else
		ret = NULL;
	return (ret);
}
