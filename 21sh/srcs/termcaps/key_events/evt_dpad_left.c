/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   evt_dpad_left.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkis <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/07 13:51:18 by bkis              #+#    #+#             */
/*   Updated: 2017/07/07 13:51:18 by bkis             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "termcaps.h"

void	evt_dpad_left(t_memory *sh)
{
	if (sh->state == HGL)
	{
		if (sh->curs.i == PROMPT_SIZE)
			return ;
		--sh->curs.i;
		highlight(sh);
		return ;
	}
	if (sh->curs.x == PROMPT_SIZE && sh->curs.y == 0)
		return ;
	--sh->curs.i;
	if (sh->curs.y > 0 && sh->curs.x == 0)
	{
		sh->curs.x = sh->curs.x_max;
		--sh->curs.y;
		tc_write("up");
		tc_write("ch+", 0, sh->curs.x_max);
	}
	else
	{
		--sh->curs.x;
		tc_write("ch+", 0, sh->curs.x);
	}
}
