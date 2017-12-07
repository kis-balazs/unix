/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkis <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/07 14:04:43 by bkis              #+#    #+#             */
/*   Updated: 2017/07/07 14:04:44 by bkis             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Includes/libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*str;

	if (s == NULL)
		return (NULL);
	str = (char*)malloc(sizeof(char) * len + 1);
	if (str == NULL)
		return (NULL);
	s = s + start;
	str = ft_strncpy(str, s, len);
	str[len] = '\0';
	return (str);
}
