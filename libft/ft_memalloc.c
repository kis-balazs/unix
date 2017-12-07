/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkis <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/10 16:40:17 by bkis              #+#    #+#             */
/*   Updated: 2017/01/10 16:52:09 by bkis             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	void *mem;

	if ((mem = (void*)malloc(size)) && size)
	{
		ft_bzero(mem, size);
		return (mem);
	}
	return (NULL);
}
