/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strint.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkis <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/07 14:02:02 by bkis              #+#    #+#             */
/*   Updated: 2017/07/07 14:02:02 by bkis             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Includes/libft.h"

static int		cmp(int to_cmp, char *cmp)
{
	while (*cmp)
	{
		if (*cmp == to_cmp)
			return (0);
		cmp++;
	}
	return (1);
}

int				ft_strint(char *str, char *str_cmp)
{
	int		i;

	i = 0;
	while (str[i] && (cmp(str[i], str_cmp)) == 0)
		i++;
	if (i == 0)
		return (0);
	return (i);
}
