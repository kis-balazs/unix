/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkis <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/07 14:01:47 by bkis              #+#    #+#             */
/*   Updated: 2017/07/07 14:01:47 by bkis             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Includes/libft.h"

char	*ft_strdup(const char *s1)
{
	int		l;
	char	*s2;

	l = ft_strlen(s1);
	if (!(s2 = (char*)malloc(sizeof(char) * l + 1)))
		return (NULL);
	if (s2 != NULL)
		ft_strcpy(s2, s1);
	else
		return (NULL);
	return (s2);
}
