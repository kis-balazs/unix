/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getndigits.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkis <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/11 12:48:08 by bkis              #+#    #+#             */
/*   Updated: 2017/03/11 12:48:10 by bkis             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_getndigits(int a)
{
	int c;

	c = 0;
	if (!a)
		return (1);
	while (a)
	{
		a /= 10;
		c++;
	}
	return (c);
}
