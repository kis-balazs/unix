/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkis <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/10 16:40:43 by bkis              #+#    #+#             */
/*   Updated: 2017/01/10 18:23:11 by bkis             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*ptr_s1;
	unsigned char	*ptr_s2;
	size_t			i;

	if (s1 == NULL || s2 == NULL)
		return (0);
	ptr_s1 = (unsigned char *)s1;
	ptr_s2 = (unsigned char *)s2;
	i = 0;
	while (i < n)
	{
		if (*(ptr_s1 + i) != *(ptr_s2 + i))
			return (*(ptr_s1 + i) - *(ptr_s2 + i));
		i++;
	}
	return (0);
}
