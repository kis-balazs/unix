/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkis <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/10 16:45:41 by bkis              #+#    #+#             */
/*   Updated: 2017/01/10 17:14:42 by bkis             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (!*needle)
		return ((char *)haystack);
	while (haystack[j] && j < len)
	{
		while (needle[i] && haystack[j + i] && haystack[j + i] ==
				needle[i] && j + i < len)
		{
			i++;
			if (ft_strlen(needle) == i)
				return ((char *)haystack + j);
		}
		i = 0;
		j++;
	}
	return (NULL);
}
