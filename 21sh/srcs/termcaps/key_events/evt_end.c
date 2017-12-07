/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   evt_end.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkis <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/07 13:51:33 by bkis              #+#    #+#             */
/*   Updated: 2017/07/07 13:51:34 by bkis             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "termcaps.h"

void	evt_end(t_memory *sh)
{
	if (sh->curs.i == sh->inp.cbuflen)
		return ;
	else if (sh->state == HGL)
	{
		sh->curs.i = sh->inp.cbuflen - 1;
		highlight(sh);
		return ;
	}
	sh->curs.i = sh->inp.cbuflen;
	sh->curs.x = sh->curs.i % sh->curs.win_x;
	if (sh->curs.y < sh->curs.y_max)
	{
		tc_write("DO+", 0, (sh->curs.y_max - sh->curs.y));
		sh->curs.y = sh->curs.y_max;
	}
	tc_write("ch+", 0, sh->curs.x);
}
