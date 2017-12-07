/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkis <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/25 19:00:19 by bkis              #+#    #+#             */
/*   Updated: 2017/01/25 19:05:28 by bkis             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static inline int	ft_print_message(char const *str)
{
	ft_putendl_fd(str, 1);
	return (1);
}

int					main(int argc, char **argv)
{
	t_tetris	tetris[MAX_T + 1];
	short		map[16];
	int			len;
	int			size;
	int			fd;

	if (argc != 2)
		return (ft_print_message("usage: fillit input_file"));
	ft_memset(tetris, sizeof(t_tetris) * (MAX_T + 1), 0);
	fd = open(argv[1], O_RDONLY, 0);
	if (!ft_read_file(fd, tetris))
		return (ft_print_message("error"));
	else
	{
		fd = open(argv[1], O_RDONLY, 0);
		len = ft_read_file(fd, tetris);
	}
	ft_memset(map, sizeof(short) * 16, 0);
	if ((size = ft_solve_square(tetris, len, map)) == 0)
		return (ft_print_message("error"));
	ft_print_result(tetris, len, size);
	close(fd);
	return (0);
}
