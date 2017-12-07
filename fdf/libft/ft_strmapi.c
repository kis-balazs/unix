/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkis <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/15 19:58:35 by bkis              #+#    #+#             */
/*   Updated: 2017/05/15 19:58:36 by bkis             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*str;
	char			*str_new;
	unsigned int	counter;

	str = (char *)s;
	if (str && f)
	{
		counter = 0;
		if (!(str_new = ft_memalloc(ft_strlen(str) + 1)))
			return (NULL);
		while (str[counter])
		{
			str_new[counter] = (*f)(counter, str[counter]);
			counter++;
		}
		str_new[counter] = '\0';
		return (str_new);
	}
	return (NULL);
}
