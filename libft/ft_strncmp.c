/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkis <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/10 16:44:49 by bkis              #+#    #+#             */
/*   Updated: 2017/01/10 17:32:34 by bkis             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (*(s1 + i) && *(s1 + i) == *(s2 + i) && n > i + 1)
		i++;
	if (n)
		return (*((unsigned char *)s1 + i) - *((unsigned char *)s2 + i));
	return (0);
}
