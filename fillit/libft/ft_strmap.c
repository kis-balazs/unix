/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkis <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/25 19:23:24 by bkis              #+#    #+#             */
/*   Updated: 2017/01/25 19:27:56 by bkis             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(const char *s, char (*f)(char))
{
	char			*d;
	unsigned int	i;

	i = 0;
	if (!s)
		return (NULL);
	d = (char *)malloc(sizeof(char) * ft_strlen(s) + 1);
	if (!d)
		return (NULL);
	while (s[i])
	{
		d[i] = f(s[i]);
		i++;
	}
	d[i] = '\0';
	return (d);
}
