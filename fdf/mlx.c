/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkis <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/15 19:49:12 by bkis              #+#    #+#             */
/*   Updated: 2017/05/15 19:49:13 by bkis             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static inline void	ft_fdf_reset(t_fdf *fdf)
{
	fdf->zoom = 0.5;
	fdf->height = 0.5;
	fdf->sin = 60;
	fdf->cos = 30;
	fdf->x_start = 50;
	fdf->y_start = 50;
	fdf->color_index = 0;
	fdf->help = 1;
	if (fdf->argv_color)
		fdf->colors[0] = fdf->argv_color;
	else
		fdf->colors[0] = WHITE;
	fdf->colors[1] = RED;
	fdf->colors[2] = YELLOW;
	fdf->colors[3] = BLUE;
	fdf->colors[4] = GREEN;
	fdf->colors[5] = PURPLE;
	fdf->colors[6] = NAVY;
	fdf->colors[7] = GRAY;
	fdf->colors[8] = ORANGE;
	fdf->colors[9] = GOLD;
}

void				ft_help(t_fdf *fdf)
{
	mlx_string_put(fdf->mlx_ptr, fdf->win_ptr, 5, 5,
			MENU_COLOR, "<Help>");
	mlx_string_put(fdf->mlx_ptr, fdf->win_ptr, 5, 20,
			MENU_COLOR, "Exit:   ESC/Q");
	mlx_string_put(fdf->mlx_ptr, fdf->win_ptr, 5, 35,
			MENU_COLOR, "Help:   F1");
	mlx_string_put(fdf->mlx_ptr, fdf->win_ptr, 5, 50,
			MENU_COLOR, "Rotate: UP RIGHT DOWN LEFT");
	mlx_string_put(fdf->mlx_ptr, fdf->win_ptr, 5, 65,
			MENU_COLOR, "Move:   8    6   2   4");
	mlx_string_put(fdf->mlx_ptr, fdf->win_ptr, 5, 80,
			MENU_COLOR, "Zoom:   + -");
	mlx_string_put(fdf->mlx_ptr, fdf->win_ptr, 5, 95,
			MENU_COLOR, "Height: H J");
	mlx_string_put(fdf->mlx_ptr, fdf->win_ptr, 5, 110,
			MENU_COLOR, "Color:  C");
}

void				ft_mlx(t_fdf *fdf)
{
	ft_fdf_reset(fdf);
	fdf->mlx_ptr = mlx_init();
	fdf->win_ptr = mlx_new_window(fdf->mlx_ptr,
			WIDTH, HEIGHT, "42 fdf");
	mlx_expose_hook(fdf->win_ptr, ft_draw, fdf);
	mlx_key_hook(fdf->win_ptr, ft_key_hook, fdf);
	mlx_loop(fdf->mlx_ptr);
}
