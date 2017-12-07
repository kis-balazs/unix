/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   evt_ctrl_dpad_up.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkis <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/07 13:50:36 by bkis              #+#    #+#             */
/*   Updated: 2017/07/07 13:50:37 by bkis             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "termcaps.h"

void	evt_ctrl_dpad_up(t_memory *sh)
{
	if (sh->state == HGL || sh->curs.y == 0)
		return ;
	--sh->curs.y;
	tc_write("up");
	if ((sh->curs.y * sh->curs.win_x) + sh->curs.x < PROMPT_SIZE)
	{
		sh->curs.i = PROMPT_SIZE;
		sh->curs.x = PROMPT_SIZE;
		tc_write("ch+", 0, sh->curs.x);
	}
	else
		sh->curs.i -= sh->curs.win_x;
}
