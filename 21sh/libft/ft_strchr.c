/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbourget <mbourget@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/17 17:04:58 by sbeline           #+#    #+#             */
/*   Updated: 2017/05/23 20:34:40 by mbourget         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Includes/libft.h"

char	*ft_strchr(const char *s, int c)
{
	size_t	i;

	if (!s)
		return (NULL);
	i = 0;
	if ((unsigned char)c == '\0')
		return ((char *)(s + ft_strlen(s)));
	while (s[i])
	{
		if ((unsigned char)s[i] == (unsigned char)c)
			return ((char *)(s + i));
		i++;
	}
	return (NULL);
}
