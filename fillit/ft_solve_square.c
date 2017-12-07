/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_solve_square.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkis <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/25 18:34:03 by bkis              #+#    #+#             */
/*   Updated: 2017/01/25 19:04:41 by bkis             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	ft_map_solve(t_tetris *tetris, int size, short *map)
{
	if (tetris->letter == 0)
		return (1);
	tetris->point.y = 0;
	while (tetris->point.y <= size - tetris->dimension.y)
	{
		tetris->point.x = 0;
		while (tetris->point.x <= size - tetris->dimension.x)
		{
			if (!(*(t_long *)(map + tetris->point.y)
						& (tetris->val >> tetris->point.x)))
			{
				*(t_long *)(map + tetris->point.y) ^=
					tetris->val >> tetris->point.x;
				if (ft_map_solve(tetris + 1, size, map))
					return (1);
				*(t_long *)(map + tetris->point.y) ^=
					tetris->val >> tetris->point.x;
			}
			tetris->point.x++;
		}
		tetris->point.y++;
	}
	return (0);
}

int	ft_solve_square(t_tetris *tetris, int count, short *map)
{
	int	size;

	size = 2;
	while (size * size < count * 4)
		size++;
	while (!ft_map_solve(tetris, size, map) && size <= 16)
	{
		ft_memset(map, sizeof(short) * 16, 0);
		size++;
	}
	if (size == 17)
		return (0);
	else
		return (size);
}
