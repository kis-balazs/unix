/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cbuf_append.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkis <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/07 13:48:40 by bkis              #+#    #+#             */
/*   Updated: 2017/07/07 13:48:41 by bkis             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "termcaps.h"

void	cbuf_append(t_memory *sh, char inp)
{
	cbuf_check_size(sh, 1);
	ft_putchar(inp);
	sh->inp.cbuf[sh->curs.i] = inp;
	++sh->inp.cbuflen;
	++sh->inp.cmdlen;
	++sh->curs.x;
	++sh->curs.i;
	if (sh->curs.x > sh->curs.x_max)
	{
		tc_write("do");
		sh->curs.x = 0;
		++sh->curs.y;
		sh->curs.y_max = sh->inp.cbuflen / sh->curs.win_x;
	}
}
