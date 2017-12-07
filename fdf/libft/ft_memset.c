/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkis <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/15 19:53:47 by bkis              #+#    #+#             */
/*   Updated: 2017/05/15 19:53:48 by bkis             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	size_t	counter;
	char	*str;

	str = (char *)b;
	if (!str)
		return (NULL);
	if (len == 0)
		return (str);
	counter = 0;
	while (counter < len)
	{
		str[counter] = (char)c;
		counter++;
	}
	return (b);
}
