/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkis <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/25 19:00:59 by bkis              #+#    #+#             */
/*   Updated: 2017/01/25 19:05:10 by bkis             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H

# define FILLIT_H
# define MAX_T 26
# include "libft.h"
# include <fcntl.h>

typedef unsigned long long	t_long;
typedef struct				s_point
{
	unsigned char x;
	unsigned char y;
}							t_point;

typedef struct				s_tetris
{
	t_long	val;
	t_point	point;
	t_point	dimension;
	char	letter;
}							t_tetris;

int							ft_test_tetrominoes(const char *str, int position);
int							ft_read_file(int fd, t_tetris *tetris);
int							ft_solve_square(t_tetris *tetris, int count,
		short *map);
void						ft_print_result(t_tetris *tetris, int count,
		int size);
t_tetris					ft_put_tetrominoes(char *str, char let);

#endif
