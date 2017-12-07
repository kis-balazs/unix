/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   highlight_cleanup.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkis <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/07 13:49:31 by bkis              #+#    #+#             */
/*   Updated: 2017/07/07 13:49:32 by bkis             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "termcaps.h"

void	highlight_cleanup(t_memory *sh, bool cut, int start)
{
	if (sh->curs.y > 0)
		tc_write("UP+", 0, sh->curs.y);
	tc_write("ch+", 0, PROMPT_SIZE);
	sh->curs.i = PROMPT_SIZE;
	tc_write("cd");
	cbuf_print(sh, false);
	if (cut)
	{
		sh->curs.i = start;
		tc_write("ch+", 0, sh->curs.x);
	}
	else
	{
		sh->curs.i = sh->curs.s_i;
		tc_write("rc");
	}
	tc_write("ve");
	sh->state = IDLE;
}
