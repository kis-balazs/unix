/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strclchr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkis <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/15 16:55:31 by bkis              #+#    #+#             */
/*   Updated: 2017/05/15 16:55:32 by bkis             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strclchr(char const *s, char c)
{
	int		len;
	char	*str;

	if (!s)
		return (0);
	str = (char *)s;
	len = 0;
	while (*str != c && *str)
	{
		str++;
		len++;
	}
	return (len);
}
