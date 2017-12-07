/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkis <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/15 16:58:15 by bkis              #+#    #+#             */
/*   Updated: 2017/05/15 16:58:15 by bkis             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strlcat(char *dest, char const *src, size_t size)
{
	char	*tmp_d;
	int		i;
	size_t	max;
	size_t	o_size;

	o_size = size;
	max = ft_strlen(dest);
	tmp_d = dest;
	while (*tmp_d && size)
	{
		tmp_d++;
		size--;
	}
	if (!size)
		return (o_size + ft_strlen(src));
	i = 0;
	while (src[i] && --size)
	{
		*tmp_d = src[i];
		tmp_d++;
		i++;
	}
	if (size && !src[i])
		*tmp_d = '\0';
	return (max + ft_strlen(src));
}
