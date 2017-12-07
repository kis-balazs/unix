/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_color_argv.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkis <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/15 19:48:19 by bkis              #+#    #+#             */
/*   Updated: 2017/05/15 19:48:19 by bkis             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static inline int	ft_hex_converter(char c)
{
	if (c >= '0' && c <= '9')
		return (c - '0');
	if (c == 'A' || c == 'a')
		return (10);
	if (c == 'B' || c == 'b')
		return (11);
	if (c == 'C' || c == 'c')
		return (12);
	if (c == 'D' || c == 'd')
		return (13);
	if (c == 'E' || c == 'e')
		return (14);
	if (c == 'F' || c == 'f')
		return (15);
	ft_exit(4);
	return (0);
}

void				ft_color_argv(char *str, t_fdf *fdf)
{
	int		i;
	int		p;
	int		n;

	if (*str != '0' || *(str + 1) != 'x')
		ft_exit(4);
	if (ft_strlen(str) > 8)
		ft_exit(4);
	str += 2;
	i = ft_strlen(str) - 1;
	n = 0;
	p = 1;
	while (i >= 0)
	{
		n += ft_hex_converter(str[i]) * p;
		p *= 16;
		i--;
	}
	fdf->argv_color = n;
}
