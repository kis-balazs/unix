/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   evt_dpad_right.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkis <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/07 13:51:23 by bkis              #+#    #+#             */
/*   Updated: 2017/07/07 13:51:23 by bkis             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "termcaps.h"

void	evt_dpad_right(t_memory *sh)
{
	if (sh->state == HGL)
	{
		if (sh->curs.i + 1 >= sh->inp.cbuflen)
			return ;
		++sh->curs.i;
		highlight(sh);
		return ;
	}
	if (sh->curs.i == sh->inp.cbuflen && sh->curs.y == sh->curs.y_max)
		return ;
	++sh->curs.i;
	if (sh->curs.x < sh->curs.x_max)
	{
		++sh->curs.x;
		tc_write("ch+", 0, sh->curs.x);
	}
	else if (sh->curs.x >= sh->curs.x_max)
	{
		sh->curs.x = 0;
		++sh->curs.y;
		tc_write("do");
	}
}
