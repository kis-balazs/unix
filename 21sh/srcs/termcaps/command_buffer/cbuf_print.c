/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cbuf_print.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkis <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/07 13:49:03 by bkis              #+#    #+#             */
/*   Updated: 2017/07/07 13:49:04 by bkis             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "termcaps.h"

void	cbuf_print(t_memory *sh, bool delete)
{
	unsigned int	y;

	if (delete)
		tc_write("sc");
	write(STDERR_FILENO, &(sh->inp.cbuf[sh->curs.i]),
		sh->inp.cbuflen - sh->curs.i);
	if (!delete)
	{
		if (sh->inp.cbuflen % sh->curs.win_x == 0)
			tc_write("do");
		y = sh->inp.cbuflen / sh->curs.win_x;
		if (y > sh->curs.y)
			tc_write("UP+", 0, y - sh->curs.y);
	}
	else
		tc_write("rc");
}
