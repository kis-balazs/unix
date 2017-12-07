/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cb_cut_internal.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkis <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/07 13:48:01 by bkis              #+#    #+#             */
/*   Updated: 2017/07/07 13:48:02 by bkis             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "termcaps.h"

void	cb_cut_internal(t_memory *sh, int start, size_t size, size_t total)
{
	unsigned int	y;
	size_t			rest;

	if (sh->inp.cbuf[total])
	{
		rest = sh->inp.cbuflen - total;
		ft_memmove(&(sh->inp.cbuf[start]), &(sh->inp.cbuf[total]), rest);
		ft_bzero(&(sh->inp.cbuf[start + rest]), size);
	}
	else
		ft_bzero(&(sh->inp.cbuf[start]), total);
	sh->inp.cbuflen -= size;
	sh->inp.cmdlen -= size;
	sh->curs.x = start % sh->curs.win_x;
	y = start / sh->curs.win_x;
	if (sh->curs.y > y)
	{
		tc_write("UP+", 0, sh->curs.y - y);
		sh->curs.y = y;
	}
	sh->curs.y_max = sh->inp.cbuflen / sh->curs.win_x;
}
