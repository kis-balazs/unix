/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wildcard.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkis <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/05 16:02:44 by bkis              #+#    #+#             */
/*   Updated: 2017/07/05 16:18:54 by bkis             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int			ft_wildcard(PF *argument, va_list ap, int i)
{
	if (argument->format[argument->index] == '*')
	{
		argument->flags[i] = va_arg(ap, int);
		if (argument->flags[i] < 0)
		{
			if (i == 1)
			{
				argument->flags[4] = 1;
				argument->flags[1] *= -1;
			}
			else if (i == 0)
			{
				argument->flags[0] = -1;
				argument->index++;
				return (0);
			}
		}
		argument->index++;
	}
	return (1);
}
