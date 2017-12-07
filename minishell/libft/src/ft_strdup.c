/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkis <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/15 16:57:13 by bkis              #+#    #+#             */
/*   Updated: 2017/05/15 16:57:14 by bkis             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(char const *s1)
{
	char *s2;

	if (!(s2 = ft_strnew(ft_strlen(s1))))
		return (s2);
	return (ft_strcpy(s2, s1));
}

char	*ft_strndup(char const *str, int len)
{
	char	*ret;
	int		c;

	c = 0;
	if (!(ret = malloc(sizeof(char) * len)))
		return (NULL);
	while (str[c] && c < len)
	{
		ret[c] = str[c];
		c++;
	}
	return (ret);
}
