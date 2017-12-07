/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_result.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkis <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/25 18:32:11 by bkis              #+#    #+#             */
/*   Updated: 2017/01/25 19:04:07 by bkis             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static inline char	*ft_generate_map(int size)
{
	char	*ptr;
	t_point	point;

	ptr = ft_strnew((size + 1) * size);
	point.y = 0;
	while (point.y < size)
	{
		point.x = 0;
		while (point.x < size)
		{
			ptr[point.y * (size + 1) + point.x] = '.';
			point.x++;
		}
		ptr[point.y * (size + 1) + point.x] = '\n';
		point.y++;
	}
	return (ptr);
}

void				ft_print_result(t_tetris *tetro, int count, int size)
{
	char	*ptr;
	t_point	point;

	ptr = ft_generate_map(size);
	while (count > 0)
	{
		point.y = 0;
		while (point.y < tetro->dimension.y)
		{
			point.x = 0;
			while (point.x < tetro->dimension.x)
			{
				if ((tetro->val >> (16 * (point.y + 1) - 1 - point.x)) & 1)
					ptr[(tetro->point.y + point.y) * (size + 1) + point.x +
						tetro->point.x] = tetro->letter;
				point.x++;
			}
			point.y++;
		}
		tetro++;
		count--;
	}
	ft_putstr(ptr);
	ft_strdel(&ptr);
}
