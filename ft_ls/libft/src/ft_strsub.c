/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkis <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/11 12:58:31 by bkis              #+#    #+#             */
/*   Updated: 2017/03/11 12:58:31 by bkis             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char *ret;

	ret = ft_strnew(len);
	if (ret)
	{
		ft_strncat(ret, (s + start), len);
		ft_strcat((ret + ft_strlen(ret)), "\0");
	}
	return (ret);
}
