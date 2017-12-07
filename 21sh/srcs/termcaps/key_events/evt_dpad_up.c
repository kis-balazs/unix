/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   evt_dpad_up.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkis <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/07 13:51:27 by bkis              #+#    #+#             */
/*   Updated: 2017/07/07 13:51:28 by bkis             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "termcaps.h"

void	evt_dpad_up(t_memory *sh)
{
	if (sh->state == HGL)
	{
		if (sh->curs.i > sh->curs.x_max
			&& (sh->curs.i - sh->curs.win_x) > PROMPT_SIZE)
			sh->curs.i -= sh->curs.win_x;
		else if (sh->curs.i > PROMPT_SIZE)
			sh->curs.i = PROMPT_SIZE;
		else
			return ;
		highlight(sh);
	}
	else if (sh->state == IDLE && sh->hst.head)
		hst_browse_prev(sh);
}
