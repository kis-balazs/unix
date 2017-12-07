/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkis <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/15 17:01:02 by bkis              #+#    #+#             */
/*   Updated: 2017/05/15 17:01:02 by bkis             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(char const *s1, char const *s2)
{
	size_t begin;
	size_t current;

	if (!*s2)
		return ((char *)s1);
	begin = 0;
	while (s1[begin] && s2)
	{
		current = 0;
		while (s2[current] && s1[begin + current] == s2[current])
			current++;
		if (current == ft_strlen(s2))
			return ((char *)(s1 + begin));
		begin++;
	}
	return (NULL);
}
