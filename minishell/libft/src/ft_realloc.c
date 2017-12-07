/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkis <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/15 16:54:38 by bkis              #+#    #+#             */
/*   Updated: 2017/05/15 16:54:39 by bkis             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_realloc(void **src, size_t src_size, size_t final_size)
{
	void	*ret;

	ret = NULL;
	if (*src && src_size < final_size)
	{
		ret = ft_memalloc(final_size);
		if (ret)
		{
			ft_memcpy(ret, *src, src_size);
			ft_memdel((void **)src);
		}
	}
	return (ret);
}
