/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cb_paste_internal.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkis <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/07 13:48:11 by bkis              #+#    #+#             */
/*   Updated: 2017/07/07 13:48:11 by bkis             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "termcaps.h"

void	cb_paste_internal(t_memory *sh)
{
	cbuf_check_size(sh, sh->cb.len);
	if (sh->curs.i < sh->inp.cbuflen)
		ft_memmove(&(sh->inp.cbuf[sh->curs.i + sh->cb.len]),
			&(sh->inp.cbuf[sh->curs.i]), sh->inp.cbuflen - sh->curs.i);
	ft_memcpy(&(sh->inp.cbuf[sh->curs.i]), sh->cb.buf, sh->cb.len);
	sh->inp.cbuflen += sh->cb.len;
	sh->inp.cmdlen += sh->cb.len;
	sh->curs.y = (sh->curs.i + sh->cb.len) / sh->curs.win_x;
	cbuf_print(sh, false);
	sh->curs.i += sh->cb.len;
	sh->curs.x = sh->curs.i % sh->curs.win_x;
	sh->curs.y_max = sh->inp.cbuflen / sh->curs.win_x;
	tc_write("ch+", 0, sh->curs.x);
}
