/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_tetrominoes.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkis <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/25 18:33:32 by bkis              #+#    #+#             */
/*   Updated: 2017/01/25 19:04:26 by bkis             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static inline t_point	*ft_new_point(int x, int y)
{
	t_point *point;

	point = ft_memalloc(sizeof(t_point));
	point->x = x;
	point->y = y;
	return (point);
}

static inline t_tetris	ft_new_tetromino(t_long val, t_point *min,
		t_point *max, char letter)
{
	t_tetris tetro;

	tetro.dimension.x = max->x - min->x + 1;
	tetro.dimension.y = max->y - min->y + 1;
	tetro.letter = letter;
	tetro.val = val;
	return (tetro);
}

static void				ft_matrix_dimension(const char *str, t_point *min,
		t_point *max)
{
	unsigned char i;
	unsigned char colnb;

	colnb = 5;
	i = 0;
	while (i < 20)
	{
		if (str[i] == '#')
		{
			if (i % colnb < min->x)
				min->x = i % colnb;
			if (i % colnb > max->x)
				max->x = i % colnb;
			if (i / colnb < min->y)
				min->y = i / colnb;
			if (i / colnb > max->y)
				max->y = i / colnb;
		}
		i++;
	}
}

t_tetris				ft_put_tetrominoes(char *str, char letter)
{
	t_tetris	tetro;
	t_point		index;
	t_point		*min;
	t_point		*max;

	min = ft_new_point(3, 3);
	max = ft_new_point(0, 0);
	ft_matrix_dimension(str, min, max);
	tetro = ft_new_tetromino(0, min, max, letter);
	index.y = 0;
	while (index.y < tetro.dimension.y)
	{
		index.x = 0;
		while (index.x < tetro.dimension.x)
		{
			if (str[(min->x + index.x) + (min->y + index.y) * 5] == '#')
				tetro.val |= (1L << (16 * (index.y + 1) - 1 - index.x));
			index.x++;
		}
		index.y++;
	}
	return (tetro);
}
