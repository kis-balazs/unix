/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   evt_printable.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkis <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/07 13:51:57 by bkis              #+#    #+#             */
/*   Updated: 2017/07/07 13:51:58 by bkis             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "termcaps.h"

void	evt_printable(t_memory *sh)
{
	if (*(sh->inp.rbuf + 1))
	{
		cb_paste_external(sh);
		return ;
	}
	if (sh->curs.i < sh->inp.cbuflen)
		cbuf_insert(sh, *sh->inp.rbuf);
	else
		cbuf_append(sh, *sh->inp.rbuf);
}
