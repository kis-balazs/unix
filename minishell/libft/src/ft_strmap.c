/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkis <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/15 16:58:33 by bkis              #+#    #+#             */
/*   Updated: 2017/05/15 16:58:34 by bkis             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	int		index;
	char	*ret;

	if (!(ret = ft_strnew(ft_strlen(s))))
		return (ret);
	index = 0;
	while (s[index])
	{
		ret[index] = (*f)(s[index]);
		index++;
	}
	ret[index] = '\0';
	return (ret);
}
