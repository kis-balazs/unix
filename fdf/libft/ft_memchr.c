/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkis <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/15 19:53:03 by bkis              #+#    #+#             */
/*   Updated: 2017/05/15 19:53:04 by bkis             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	char	*str;
	size_t	counter;

	if (!(str = (char *)s))
		return (NULL);
	counter = 0;
	while (counter < n)
	{
		if ((char)c == str[0])
			return ((void*)str);
		str++;
		counter++;
	}
	return (NULL);
}
