/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkis <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/21 16:48:52 by bkis              #+#    #+#             */
/*   Updated: 2017/02/22 17:05:25 by bkis             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int			ft_lung(char *array, char *str)
{
	int				i;
	int				j;

	i = 0;
	j = 0;
	while (str[i])
		i++;
	while (array[j])
		j++;
	return (j - i);
}

static int			ft_read_file(int const fd, char **array)
{
	char			*s;
	int				nr;
	char			*str;

	s = (char *)malloc(sizeof(*s) * (BUFF_SIZE + 1));
	if (!s)
		return (-1);
	nr = read(fd, s, BUFF_SIZE);
	if (nr > 0)
	{
		s[nr] = '\0';
		str = ft_strjoin(*array, s);
		free(*array);
		*array = str;
	}
	free(s);
	return (nr);
}

int					get_next_line(int const fd, char **line)
{
	int				nr;
	static char		*array = NULL;
	char			*str;

	if ((!array && (array = (char *)malloc(sizeof(*array))) == NULL) || !line
			|| BUFF_SIZE < 0 || fd < 0)
		return (-1);
	str = ft_strchr(array, '\n');
	while (str == NULL)
	{
		nr = ft_read_file(fd, &array);
		if (nr == 0)
		{
			if (ft_strlen(array) == 0)
				return (0);
			array = ft_strjoin(array, "\n");
		}
		if (nr < 0)
			return (-1);
		else
			str = ft_strchr(array, '\n');
	}
	*line = ft_strsub(array, 0, ft_lung(array, str));
	array = ft_strdup(str + 1);
	return (1);
}
