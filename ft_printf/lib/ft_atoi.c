/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkis <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/05 16:22:23 by bkis              #+#    #+#             */
/*   Updated: 2017/07/05 16:22:24 by bkis             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_atoi(const char *nbr)
{
	int result;
	int neg;

	result = 0;
	neg = 0;
	while (*nbr == ' ' || ft_isescaped(*nbr))
		nbr++;
	if (*nbr == '-' || *nbr == '+')
		neg = (*(nbr++) == '-') ? 1 : 0;
	while (*nbr && ft_isdigit(*nbr))
		result = result * 10 + (*(nbr++) - 48);
	return (neg ? result * -1 : result);
}
