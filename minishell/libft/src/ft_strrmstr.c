/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrmstr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkis <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/15 17:00:49 by bkis              #+#    #+#             */
/*   Updated: 2017/05/15 17:00:49 by bkis             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrmstr(char *str, char *torm)
{
	char	*subs;
	int		c;
	int		sec;
	int		len;

	c = 0;
	sec = 0;
	len = ft_strlen(str);
	if (!(subs = ft_strstr(str, torm)))
		return (str);
	while (str[c] && c < len)
	{
		if ((str + c) == subs)
			sec += ft_strlen(torm);
		str[c] = (c + sec) <= len ? str[c + sec] : 0;
		c++;
	}
	str[c] = 0;
	return (str);
}
