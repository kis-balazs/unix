/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ptr_conv.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkis <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/05 16:01:02 by bkis              #+#    #+#             */
/*   Updated: 2017/07/05 16:29:39 by bkis             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	pointer_handler(PF *argument, va_list ap)
{
	uintmax_t	n;

	n = va_arg(ap, uintmax_t);
	if (!(argument->arg = ft_strlower(ft_itoa_base(n, 16))))
		return (-1);
	return (ft_print_number(argument, "0x"));
}

int	prc_handler(PF *argument, va_list ap)
{
	argument->arg = "%";
	ft_print_character(argument);
	return ((int)ap);
}
