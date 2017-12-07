/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkis <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/07 14:03:57 by bkis              #+#    #+#             */
/*   Updated: 2017/07/07 14:03:58 by bkis             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Includes/libft.h"

char	*ft_strndup(char *s, int begin, int end)
{
	char	*ret;
	int		i;

	i = 0;
	if (!(ret = (char*)malloc(sizeof(char) * (end - begin) + 1)))
		return (NULL);
	while (begin < end)
	{
		ret[i] = s[begin];
		i++;
		begin++;
	}
	ret[i] = '\0';
	return (ret);
}
