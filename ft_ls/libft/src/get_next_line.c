/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkis <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/11 13:00:11 by bkis              #+#    #+#             */
/*   Updated: 2017/03/11 13:00:12 by bkis             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		buff_delfline(char **buff)
{
	char	*new;
	int		ret;

	ret = 0;
	if (!buff || !*buff || !**buff)
		return (0);
	new = NULL;
	if ((new = ft_strnew(ft_strlen(*buff) - ft_strclchr(*buff, '\n'))))
		new = ft_strcpy(new, (*buff + 1 + ft_strclchr(*buff, '\n')));
	else
		ret = -1;
	ft_strdel(buff);
	*buff = new;
	return (ret);
}

static int		ft_str_read_add(int fd, char **buff)
{
	char	*tmp;
	int		len;

	len = ft_strlen(*buff);
	tmp = ft_strdup(*buff);
	ft_strdel(buff);
	*buff = ft_strnew(len + BUFF_SIZE);
	ft_strcat(*buff, tmp);
	ft_strdel(&tmp);
	return (read(fd, (*buff + len), BUFF_SIZE));
}

static t_file	*f_add(int fd, t_file *link)
{
	t_file	*ret;

	if ((ret = (t_file *)ft_memalloc(sizeof(t_file))))
	{
		ret->fd = fd;
		ret->buff = (char *)ft_memalloc(BUFF_SIZE);
		if (link && !link->nxt)
		{
			ret->nxt = link;
			link->nxt = ret;
		}
		else if (link && link->nxt)
		{
			ret->nxt = link->nxt;
			link->nxt = ret;
		}
		else
			ret->nxt = NULL;
	}
	return (ret);
}

int				get_next_line(int const fd, char **line)
{
	static t_file	*f = NULL;
	int				ret;
	int				s_fd;

	ret = 0;
	if (fd < 0 || !line || read(fd, NULL, 0) != 0)
		return (-1);
	s_fd = (f) ? f->fd : -1;
	while (!f || f->fd != fd)
	{
		(f && f->nxt) ? f = f->nxt : (void)0;
		(!f || f->fd == s_fd) ? f = f_add(fd, f) : (void)0;
	}
	s_fd = 1;
	while (s_fd > 0 && f->buff && !ft_strchr(f->buff, '\n'))
		if ((s_fd = ft_str_read_add(fd, &f->buff)) == -1)
			ret = -1;
	if ((s_fd || *f->buff) && (*line = ft_strnew(ft_strclchr(f->buff, '\n'))))
		ret = (ft_strncpy(*line, f->buff, ft_strclchr(f->buff, '\n'))) ? 1 : -1;
	else if (s_fd || *f->buff)
		ret = -1;
	(buff_delfline(&f->buff)) == -1 ? ret = -1 : (void)0;
	return ((ret == 1 && !f->buff) ? 0 : ret);
}
