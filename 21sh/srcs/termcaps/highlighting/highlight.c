/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   highlight.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkis <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/07 13:49:25 by bkis              #+#    #+#             */
/*   Updated: 2017/07/07 13:49:26 by bkis             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "termcaps.h"

void		highlight(t_memory *sh)
{
	int		start;
	int		end;

	if (sh->curs.y > 0)
		tc_write("UP+", 0, sh->curs.y);
	tc_write("ch+", 0, PROMPT_SIZE);
	tc_write("cd");
	if (sh->curs.s_i < sh->curs.i)
	{
		start = sh->curs.s_i;
		end = sh->curs.i + 1;
	}
	else
	{
		start = sh->curs.i;
		end = sh->curs.s_i + 1;
	}
	write(STDOUT_FILENO, sh->inp.cmd, start - PROMPT_SIZE);
	tc_write("so");
	write(STDOUT_FILENO, &(sh->inp.cbuf[start]), end - start);
	tc_write("se");
	write(STDOUT_FILENO, &(sh->inp.cbuf[end]), sh->inp.cbuflen - end);
	tc_write("rc");
}
