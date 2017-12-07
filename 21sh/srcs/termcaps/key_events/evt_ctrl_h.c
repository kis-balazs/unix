/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   evt_ctrl_h.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkis <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/07 13:50:48 by bkis              #+#    #+#             */
/*   Updated: 2017/07/07 13:50:49 by bkis             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "termcaps.h"

void	evt_ctrl_h(t_memory *sh)
{
	if (sh->state != HGL && sh->curs.i >= sh->inp.cbuflen)
		return ;
	else if (sh->state == HGL)
	{
		highlight_cleanup(sh, false, 0);
		return ;
	}
	sh->state = HGL;
	tc_write("sc");
	tc_write("vi");
	sh->curs.s_i = sh->curs.i;
	highlight(sh);
}
