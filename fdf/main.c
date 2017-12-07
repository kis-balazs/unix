/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkis <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/15 19:49:05 by bkis              #+#    #+#             */
/*   Updated: 2017/05/15 19:49:06 by bkis             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_exit(int offset)
{
	char	**msg;

	msg = (char**)malloc(sizeof(char*) * 5);
	msg[0] = "Usage: ./fdf <filename> [optional: color]\n\
Color format: 0xFFFFFF\n";
	msg[1] = "No file opened. Exiting.\n";
	msg[2] = "Found wrong line length. Exiting\n";
	msg[3] = "No data found. Exiting.\n";
	msg[4] = "Invalid color. Exiting.\n";
	ft_putstr(msg[offset]);
	exit(EXIT_SUCCESS);
}

int		main(int argc, char **argv)
{
	t_fdf	fdf;

	if (argc < 2 || argc > 3)
		ft_exit(0);
	else
	{
		fdf.argv_color = 0;
		if (argc == 3)
			ft_color_argv(argv[2], &fdf);
		fdf.map = ft_read_map(argv[1]);
		ft_mlx(&fdf);
	}
	return (0);
}
