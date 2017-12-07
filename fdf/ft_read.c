/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkis <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/15 19:48:31 by bkis              #+#    #+#             */
/*   Updated: 2017/05/15 19:48:31 by bkis             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static inline void				ft_reset(char ***src)
{
	int	i;

	i = 0;
	while (*src[i])
	{
		free(*src[i]);
		i++;
	}
}

static inline t_coordinates		*ft_read_line(char *str, int size)
{
	t_coordinates				*c_sys;
	char						**temp;
	int							i;

	i = 0;
	c_sys = (t_coordinates *)malloc(sizeof(c_sys) * size * 2);
	temp = ft_strsplit(str, ' ');
	while (temp[i])
	{
		c_sys[i].x = 0;
		c_sys[i].y = 0;
		c_sys[i].z = ft_atoi(temp[i]);
		i++;
	}
	ft_reset(&temp);
	return (c_sys);
}

static inline void				ft_read_c_sys(t_map **map, int fd, char *file)
{
	char	*line;
	int		i;

	i = 0;
	fd = open(file, O_RDONLY);
	if (!((*map)->c_sys = (t_coordinates**)malloc(sizeof(t_coordinates*) *
					(*map)->height)))
		return ;
	while (get_next_line(fd, &line))
	{
		(*map)->c_sys[i] = ft_read_line(line, (*map)->width);
		i++;
	}
	close(fd);
}

static inline void				ft_map_size(t_map **map, int fd)
{
	int		rows;
	int		aux;
	int		cols;
	char	*line;

	rows = 0;
	cols = 0;
	aux = 0;
	while (get_next_line(fd, &line))
	{
		if (line == NULL)
			ft_exit(1);
		if (rows == 0)
			cols = ft_line_len(line);
		aux = ft_line_len(line);
		if (cols != aux)
			ft_exit(2);
		rows++;
	}
	free(line);
	if (rows == 0)
		ft_exit(3);
	(*map)->height = rows;
	(*map)->width = cols;
	close(fd);
}

t_map							*ft_read_map(char *file)
{
	t_map	*map;
	int		fd;

	map = (t_map*)malloc(sizeof(t_map));
	if ((fd = open(file, O_RDONLY)) == -1)
		ft_exit(1);
	ft_map_size(&map, fd);
	ft_read_c_sys(&map, fd, file);
	return (map);
}
