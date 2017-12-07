/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cbuf_insert.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkis <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/07 13:48:54 by bkis              #+#    #+#             */
/*   Updated: 2017/07/07 13:48:56 by bkis             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "termcaps.h"

void	cbuf_insert(t_memory *sh, char inp)
{
	cbuf_check_size(sh, 1);
	ft_memmove(&(sh->inp.cbuf[sh->curs.i + 1]), &(sh->inp.cbuf[sh->curs.i]),
		(sh->inp.cbuflen - sh->curs.i));
	sh->inp.cbuf[sh->curs.i] = inp;
	tc_write("cd");
	++sh->inp.cbuflen;
	++sh->inp.cmdlen;
	sh->curs.y_max = sh->inp.cbuflen / sh->curs.win_x;
	cbuf_print(sh, false);
	evt_dpad_right(sh);
}
