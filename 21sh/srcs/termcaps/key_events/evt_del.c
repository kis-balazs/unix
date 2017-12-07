/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   evt_del.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkis <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/07 13:51:02 by bkis              #+#    #+#             */
/*   Updated: 2017/07/07 13:51:03 by bkis             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "termcaps.h"

void	evt_del(t_memory *sh)
{
	if (sh->state == HGL)
		return ;
	else if (!sh->inp.cbuf[sh->curs.i])
	{
		tc_write("bl");
		return ;
	}
	ft_memmove(&(sh->inp.cbuf[sh->curs.i]), &(sh->inp.cbuf[sh->curs.i + 1]),
		(sh->inp.cbuflen - sh->curs.i));
	tc_write("cd");
	--sh->inp.cbuflen;
	--sh->inp.cmdlen;
	sh->curs.y_max = sh->inp.cbuflen / sh->curs.win_x;
	cbuf_print(sh, true);
	tc_write("ch+", 0, sh->curs.x);
}
