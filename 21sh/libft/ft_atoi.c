/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkis <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/07 13:53:52 by bkis              #+#    #+#             */
/*   Updated: 2017/07/07 13:53:53 by bkis             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Includes/libft.h"

int		ft_atoi(const char *str)
{
	int		i;
	int		n;
	int		boolean;

	i = 0;
	n = 0;
	boolean = -1;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n' || str[i] == '\r'
				|| str[i] == '\f' || str[i] == '\v')
		i++;
	if (str[i] == 45 || str[i] == 43)
	{
		if (str[i] == 45)
			boolean = -boolean;
		i++;
	}
	while (str[i] > 47 && str[i] < 58)
	{
		n = (10 * n - (str[i] - 48));
		i++;
	}
	return (n * boolean);
}
