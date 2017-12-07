/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkis <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/25 19:23:02 by bkis              #+#    #+#             */
/*   Updated: 2017/01/25 19:27:21 by bkis             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*dest;

	if (!s1 || !s2)
		return (NULL);
	dest = ft_strnew(ft_strlen(s1) + ft_strlen(s2));
	if (!dest)
		return (NULL);
	dest = ft_strcpy(dest, s1);
	dest = ft_strcat(dest, s2);
	return (dest);
}
