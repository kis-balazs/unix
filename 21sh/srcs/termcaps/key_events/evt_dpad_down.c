/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   evt_dpad_down.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkis <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/07 13:51:11 by bkis              #+#    #+#             */
/*   Updated: 2017/07/07 13:51:13 by bkis             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "termcaps.h"

void	evt_dpad_down(t_memory *sh)
{
	if (sh->state == HGL)
	{
		if (sh->curs.i + sh->curs.win_x < sh->inp.cbuflen)
			sh->curs.i += sh->curs.win_x;
		else if (sh->curs.i < sh->inp.cbuflen - 1)
			sh->curs.i = sh->inp.cbuflen - 1;
		else
			return ;
		highlight(sh);
		return ;
	}
	else if (sh->state == IDLE && sh->hst.browsing)
		hst_browse_next(sh);
}
