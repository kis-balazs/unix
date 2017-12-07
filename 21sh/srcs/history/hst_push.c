/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hst_push.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkis <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/07 13:26:56 by bkis              #+#    #+#             */
/*   Updated: 2017/07/07 13:26:57 by bkis             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "termcaps.h"

static char	*build_and_write_line(t_memory *sh)
{
	char			*line;
	int				fd;

	line = ft_itoa(sh->code_history);
	line = ft_strmerge(line, ";", 1, 0);
	line = ft_strmerge(line, sh->inp.cmd, 1, 0);
	if (search_env(g_env, "HISTORY="))
	{
		fd = open(search_env(g_env, "HISTORY="),
				O_WRONLY | O_CREAT | O_APPEND, 0666);
		write(fd, line, ft_strlen(line));
		write(fd, "\n", 1);
		close(fd);
	}
	sh->code_history++;
	return (line);
}

void		hst_push(t_memory *sh, char *line)
{
	t_hlst	*node;

	node = (t_hlst *)ft_memalloc(sizeof(t_hlst));
	node->line = (line == NULL ? build_and_write_line(sh) : ft_strdup(line));
	node->cmd = ft_strchr(node->line, ';') + 1;
	node->cmdlen = (line == NULL ? sh->inp.cmdlen : ft_strlen(node->cmd));
	if (sh->state == ENCL && sh->hst.tmphead == NULL)
		sh->hst.tmphead = node;
	if (!sh->hst.head)
		sh->hst.head = node;
	else
	{
		sh->hst.current = sh->hst.end;
		node->prev = sh->hst.current;
		sh->hst.current->next = node;
	}
	sh->hst.current = node;
	sh->hst.end = node;
}
