/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   evt_ctrl_dpad_right.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkis <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/07 13:50:30 by bkis              #+#    #+#             */
/*   Updated: 2017/07/07 13:50:30 by bkis             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "termcaps.h"

void	evt_ctrl_dpad_right(t_memory *sh)
{
	if (sh->state == HGL)
		return ;
	while (!ft_isalnum(sh->inp.cbuf[sh->curs.i])
		&& sh->curs.i < sh->inp.cbuflen)
		evt_dpad_right(sh);
	while (ft_isalnum(sh->inp.cbuf[sh->curs.i]) && sh->curs.i < sh->inp.cbuflen)
		evt_dpad_right(sh);
}
