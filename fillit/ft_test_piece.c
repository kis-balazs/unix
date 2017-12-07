/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_test_piece.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkis <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/25 18:34:13 by bkis              #+#    #+#             */
/*   Updated: 2017/01/25 19:04:48 by bkis             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static inline int	ft_ortho_connection(const char *str)
{
	int	i;
	int	connection;

	i = 0;
	connection = 0;
	while (i < 20)
	{
		if (str[i] == '#')
		{
			if ((i + 1) < 20 && str[i + 1] == '#')
				connection++;
			if ((i - 1) >= 0 && str[i - 1] == '#')
				connection++;
			if ((i + 5) < 20 && str[i + 5] == '#')
				connection++;
			if ((i - 5) >= 0 && str[i - 5] == '#')
				connection++;
		}
		i++;
	}
	if (!(connection == 6 || connection == 8))
		return (0);
	return (1);
}

int					ft_test_tetrominoes(const char *str, int len)
{
	int	i;
	int	squares;

	i = 0;
	squares = 0;
	while (i < 20)
	{
		if (i % 5 < 4)
		{
			if (!(str[i] == '#' || str[i] == '.'))
				return (0);
			if (str[i] == '#' && ++squares > 4)
				return (0);
		}
		else if (str[i] != '\n')
			return (0);
		i++;
	}
	if (len == 21 && str[20] != '\n')
		return (0);
	if (!ft_ortho_connection(str))
		return (0);
	return (1);
}
