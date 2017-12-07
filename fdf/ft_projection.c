/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_projection.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkis <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/15 19:48:25 by bkis              #+#    #+#             */
/*   Updated: 2017/05/15 19:48:26 by bkis             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_iso_projection(t_fdf *fdf)
{
	double		sin_angle;
	double		cos_angle;
	double		spacing;
	int			i;
	int			j;

	sin_angle = sin(fdf->sin * M_PI / 180);
	cos_angle = cos(fdf->cos * M_PI / 180);
	spacing = fdf->zoom * (WIDTH / (fdf->map->height * 0.5 + fdf->map->width
				* 0.86));
	i = -1;
	while (++i < fdf->map->height)
	{
		j = -1;
		while (++j < fdf->map->width)
		{
			fdf->map->c_sys[i][j].x = (i - fdf->map->height / 2) * spacing
				* -cos_angle + (j - fdf->map->width / 2) * spacing
				* cos_angle + WIDTH / 2 + fdf->x_start;
			fdf->map->c_sys[i][j].y = (i - fdf->map->height / 2) * spacing
				* sin_angle - (j - fdf->map->width / 2) * spacing * -sin_angle
				- fdf->map->c_sys[i][j].z * fdf->height * spacing
				+ HEIGHT / 2 + fdf->y_start;
		}
	}
}

int		ft_line_len(char *str)
{
	int		len;

	len = 0;
	while (*str)
	{
		while (*str == ' ')
			str++;
		if (*str)
		{
			len++;
			while (*str && *str != ' ')
				str++;
		}
	}
	return (len);
}
