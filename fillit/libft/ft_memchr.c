/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkis <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/25 18:42:51 by bkis              #+#    #+#             */
/*   Updated: 2017/01/25 19:19:44 by bkis             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const char	*ptr_s;
	size_t		i;

	ptr_s = (const char *)s;
	i = 0;
	if (s == NULL)
		return (NULL);
	while (i < n)
	{
		if (*(ptr_s + i) == (char)c)
			return ((void *)ptr_s + i);
		i++;
	}
	return (NULL);
}
