/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   evt_ctrl_dpad_left.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkis <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/07 13:50:22 by bkis              #+#    #+#             */
/*   Updated: 2017/07/07 13:50:23 by bkis             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "termcaps.h"

void	evt_ctrl_dpad_left(t_memory *sh)
{
	if (sh->state == HGL)
		return ;
	if (sh->curs.i - 1 > PROMPT_SIZE)
	{
		evt_dpad_left(sh);
		while (!ft_isalnum(sh->inp.cbuf[sh->curs.i - 1])
			&& sh->curs.i - 1 > PROMPT_SIZE)
			evt_dpad_left(sh);
		while (ft_isalnum(sh->inp.cbuf[sh->curs.i - 1])
			&& sh->curs.i - 1 >= PROMPT_SIZE)
			evt_dpad_left(sh);
	}
}
