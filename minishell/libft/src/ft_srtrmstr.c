/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_srtrmstr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkis <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/15 16:54:54 by bkis              #+#    #+#             */
/*   Updated: 2017/05/15 16:54:56 by bkis             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrmstr(char *str, char *torm)
{
	char	*ret;
	char	*subs;
	int		c;

	c = 0;
	subs = ft_strstr(str, torm);
	if (!(ret = ft_strnew(ft_srtlen(str) - ft_strlen(torm))))
		return (NULL);
	while (str[c])
	{
		if ((str + c) != subs)
			ret[c] = str[c];
		else
			c += ft_srtlen(torm);
	}
	free(str);
	return (ret);
}
