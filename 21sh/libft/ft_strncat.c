/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkis <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/07 14:03:22 by bkis              #+#    #+#             */
/*   Updated: 2017/07/07 14:03:23 by bkis             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Includes/libft.h"

char	*ft_strncat(char *s1, const char *s2, size_t n)
{
	size_t	len;
	size_t	i;

	i = 0;
	len = 0;
	while (s1[len])
		len++;
	while (s2[i] != '\0' && i < n)
	{
		s1[len] = s2[i];
		i++;
		len++;
	}
	s1[len] = '\0';
	return (s1);
}
