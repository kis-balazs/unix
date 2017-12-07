/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkis <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/15 19:48:09 by bkis              #+#    #+#             */
/*   Updated: 2017/05/15 19:48:10 by bkis             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static inline void			ft_set_draw_struct(t_draw *draw, t_point pts)
{
	draw->dx = abs(pts.x1 - pts.x0);
	draw->dy = abs(pts.y1 - pts.y0);
	if (pts.x0 < pts.x1)
		draw->sx = 1;
	else
		draw->sx = -1;
	if (pts.y0 < pts.y1)
		draw->sy = 1;
	else
		draw->sy = -1;
	if (draw->dx > draw->dy)
		draw->err = draw->dx / 2;
	else
		draw->err = -draw->dy / 2;
	draw->e2 = 0;
}

static inline void			ft_draw_line(t_point pts, t_draw draw, t_fdf *fdf)
{
	while (1)
	{
		mlx_pixel_put(fdf->mlx_ptr, fdf->win_ptr, pts.x0, pts.y0,
				fdf->colors[fdf->color_index]);
		if (pts.x0 == pts.x1 && pts.y0 == pts.y1)
			return ;
		draw.e2 = draw.err;
		if (draw.e2 > -draw.dx)
		{
			draw.err -= draw.dy;
			pts.x0 += draw.sx;
		}
		if (draw.e2 < draw.dy)
		{
			draw.err += draw.dx;
			pts.y0 += draw.sy;
		}
	}
}

static inline void			ft_draw_ij(t_fdf *fdf, int i, int j)
{
	t_draw		draw;
	t_point		pts;

	if (j < fdf->map->width - 1)
	{
		pts.x0 = fdf->map->c_sys[i][j].x;
		pts.y0 = fdf->map->c_sys[i][j].y;
		pts.x1 = fdf->map->c_sys[i][j + 1].x;
		pts.y1 = fdf->map->c_sys[i][j + 1].y;
		ft_set_draw_struct(&draw, pts);
		ft_draw_line(pts, draw, fdf);
	}
	if (i < fdf->map->height - 1)
	{
		pts.x0 = fdf->map->c_sys[i][j].x;
		pts.y0 = fdf->map->c_sys[i][j].y;
		pts.x1 = fdf->map->c_sys[i + 1][j].x;
		pts.y1 = fdf->map->c_sys[i + 1][j].y;
		ft_set_draw_struct(&draw, pts);
		ft_draw_line(pts, draw, fdf);
	}
}

int							ft_draw(t_fdf *fdf)
{
	int			i;
	int			j;

	i = 0;
	mlx_clear_window(fdf->mlx_ptr, fdf->win_ptr);
	ft_iso_projection(fdf);
	while (i < fdf->map->height)
	{
		j = 0;
		while (j < fdf->map->width)
		{
			ft_draw_ij(fdf, i, j);
			j++;
		}
		i++;
	}
	if (fdf->help)
		ft_help(fdf);
	return (0);
}
