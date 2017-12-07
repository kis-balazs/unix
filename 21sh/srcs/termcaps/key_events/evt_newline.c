/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   evt_newline.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkis <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/07 13:51:50 by bkis              #+#    #+#             */
/*   Updated: 2017/07/07 13:51:50 by bkis             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "termcaps.h"

static void		enclosing_check(t_memory *sh)
{
	static char	*enclosing_chars = "\x22\x27";
	int			i;
	int			j;

	i = -1;
	j = -1;
	while (sh->inp.cmd[++i])
	{
		if (sh->inp.missing && sh->inp.cmd[i] == sh->inp.missing)
			sh->inp.missing = 0;
		else if (!sh->inp.missing)
		{
			while (enclosing_chars[++j])
				if (sh->inp.cmd[i] == enclosing_chars[j])
					sh->inp.missing = enclosing_chars[j];
			j = -1;
		}
	}
}

static void		clear_tmp_history(t_memory *sh, t_hlst *saved)
{
	t_hlst	*tmp;

	tmp = saved;
	if (sh->hst.head != sh->hst.tmphead)
	{
		sh->hst.current = sh->hst.tmphead->prev;
		sh->hst.end = sh->hst.current;
		sh->hst.tmphead->prev->next = NULL;
	}
	while (saved)
	{
		tmp = saved;
		saved = saved->next;
		ft_strdel(&(tmp->cmd));
		free(tmp);
	}
	if (sh->hst.head == sh->hst.tmphead)
		ft_bzero(&(sh->hst), sizeof(t_history));
	else
		sh->hst.tmphead = NULL;
}

static void		restore_to_buffer(t_memory *sh, char *cmd, t_hlst *saved)
{
	char	*buf;
	size_t	total;

	total = 0;
	while (saved)
	{
		total += saved->cmdlen;
		saved = saved->next;
	}
	saved = sh->hst.tmphead;
	total = total + sh->inp.cmdlen;
	buf = (char *)ft_memalloc(total + 1);
	while (saved)
	{
		ft_strcat(buf, saved->cmd);
		saved = saved->next;
	}
	ft_strcat(buf, cmd);
	ft_memcpy(cmd, buf, total);
	sh->inp.cmdlen = total;
	ft_strdel(&buf);
	clear_tmp_history(sh, sh->hst.tmphead);
}

static void		handle_incomplete_enclosing(t_memory *sh)
{
	enclosing_check(sh);
	if (sh->inp.missing)
	{
		if (sh->state == IDLE)
			sh->state = ENCL;
		cbuf_check_size(sh, 1);
		sh->inp.cmd[sh->inp.cmdlen++] = '\n';
		hst_tmp_push(sh);
		*sh->inp.cbuf = '>';
	}
	else if (!sh->inp.missing && sh->state == ENCL)
	{
		sh->state = IDLE;
		*sh->inp.cbuf = '$';
		restore_to_buffer(sh, sh->inp.cmd, sh->hst.tmphead);
		sh->inp.multi_line = true;
	}
}

void			evt_newline(t_memory *sh)
{
	if (sh->state == HGL)
	{
		cb_copy_internal(sh, false);
		return ;
	}
	handle_incomplete_enclosing(sh);
	ft_putchar('\n');
	if (sh->state == IDLE && sh->inp.cmdlen > 0
		&& !from_deep_space(sh->inp.cmd, sh->inp.cmdlen))
		sh->inp.ready = true;
	else
		cbuf_reset(sh);
}
