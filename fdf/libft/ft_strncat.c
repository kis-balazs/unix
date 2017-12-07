/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkis <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/15 19:58:53 by bkis              #+#    #+#             */
/*   Updated: 2017/05/15 19:58:53 by bkis             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *s1, const char *s2, size_t n)
{
	size_t	size;
	size_t	i;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	i = 0;
	size = ft_strlen(s1);
	while (s2[i] && i < n)
	{
		s1[size + i] = s2[i];
		i++;
	}
	s1[size + i] = '\0';
	return (s1);
}
