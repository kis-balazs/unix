/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hst_retrieve.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkis <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/07 13:27:09 by bkis              #+#    #+#             */
/*   Updated: 2017/07/07 13:27:10 by bkis             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "termcaps.h"

void	hst_retrieve(t_memory *sh)
{
	char		*line;
	char		*cmd;
	int			fd;

	fd = open(search_env(g_env, "HISTORY="), O_RDONLY | O_CREAT, 0666);
	line = NULL;
	while (get_next_line(fd, &line) > 0)
	{
		if (line)
		{
			if ((cmd = ft_strchr(line, ';')) != NULL && *(cmd + 1) != 0)
				hst_push(sh, line);
			ft_strdel(&line);
		}
		sh->code_history++;
	}
	close(fd);
}
