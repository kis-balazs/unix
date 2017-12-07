/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkis <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/15 16:58:39 by bkis              #+#    #+#             */
/*   Updated: 2017/05/15 16:58:40 by bkis             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		index;
	char	*ret;

	if (!(ret = ft_strnew(ft_strlen(s))))
		return (ret);
	index = 0;
	while (s[index])
	{
		ret[index] = (*f)(index, s[index]);
		index++;
	}
	ret[index] = '\0';
	return (ret);
}
