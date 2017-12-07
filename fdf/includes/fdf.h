/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkis <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/15 19:48:57 by bkis              #+#    #+#             */
/*   Updated: 2017/05/15 19:48:58 by bkis             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include <mlx.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <math.h>
# include "../libft/libft.h"
# include "../libft/get_next_line.h"
# define WIDTH              800
# define HEIGHT             700
# define KEY_ESC            53
# define KEY_Q              12
# define KEY_LEFT_ARROW     123
# define KEY_RIGHT_ARROW    124
# define KEY_DOWN_ARROW     125
# define KEY_UP_ARROW       126
# define KEY_ZOOM_IN        69
# define KEY_ZOOM_OUT       78
# define KEY_COLOR          8
# define KEY_HEIGHT_UP      4
# define KEY_HEIGHT_DOWN    38
# define KEY_MOVE_UP        91
# define KEY_MOVE_DOWN      84
# define KEY_MOVE_RIGHT     88
# define KEY_MOVE_LEFT      86
# define KEY_HELP           122
# define WHITE              0xFFFFFF
# define RED                0xFF0000
# define YELLOW             0xFFFF00
# define BLUE               0x0000FF
# define GREEN              0x33CC33
# define PURPLE             0x9900FF
# define NAVY               0x9966FF
# define GRAY               0x808080
# define ORANGE             0xFFA500
# define GOLD               0xFFD700
# define MENU_COLOR         0xFFFFFF

typedef struct		s_point
{
	int		x0;
	int		y0;
	int		x1;
	int		y1;
}					t_point;

typedef struct		s_draw
{
	int		dx;
	int		dy;
	int		sx;
	int		sy;
	int		err;
	int		e2;
}					t_draw;

typedef struct		s_coordinates
{
	int		x;
	int		y;
	int		z;
}					t_coordinates;

typedef struct		s_map
{
	t_coordinates	**c_sys;
	int				width;
	int				height;
}					t_map;

typedef struct		s_fdf
{
	void	*mlx_ptr;
	void	*win_ptr;
	t_map	*map;
	double	zoom;
	double	height;
	int		sin;
	int		cos;
	int		x_start;
	int		y_start;
	int		colors[10];
	int		color_index;
	int		argv_color;
	int		help;
}					t_fdf;

t_map				*ft_read_map(char *file);
void				ft_iso_projection(t_fdf *fdf);
void				ft_exit(int error);
int					ft_line_len(char *str);
void				ft_color_argv(char *str, t_fdf *fdf);
void				ft_help(t_fdf *fdf);
int					ft_key_hook(int keycode, t_fdf *fdf);
int					ft_draw(t_fdf *fdf);
void				ft_mlx(t_fdf *fdf);

#endif
