/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkis <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/07 14:02:31 by bkis              #+#    #+#             */
/*   Updated: 2017/07/07 14:02:32 by bkis             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Includes/libft.h"

char		*ft_strjoin(char const *s1, char const *s2)
{
	char	*s3;
	size_t	i;

	if (!s1 || !s2)
		return (NULL);
	s3 = (char*)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (s3)
	{
		i = 0;
		while (*s1)
		{
			s3[i++] = *s1;
			s1++;
		}
		while (*s2)
		{
			s3[i++] = *s2;
			s2++;
		}
		s3[i] = '\0';
	}
	return (s3);
}
