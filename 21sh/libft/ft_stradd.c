/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stradd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkis <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/07 14:00:34 by bkis              #+#    #+#             */
/*   Updated: 2017/07/07 14:00:35 by bkis             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Includes/libft.h"

char	*ft_stradd(char **s1, char **s2)
{
	char	*str;
	void	*b;
	int		i;

	i = ft_strlen(*s1) + ft_strlen(*s2);
	if ((str = (char *)malloc(sizeof(char) * (i + 1))) == NULL)
		return (NULL);
	b = str;
	i = 0;
	while ((*s1)[i])
		*str++ = (*s1)[i++];
	i = 0;
	while ((*s2)[i])
		*str++ = (*s2)[i++];
	*str = '\0';
	if (*s1)
		ft_strdel(s1);
	if (*s2)
		ft_strdel(s2);
	return (b);
}
