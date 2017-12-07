/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cbuf_reset.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkis <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/07 13:49:10 by bkis              #+#    #+#             */
/*   Updated: 2017/07/07 13:49:11 by bkis             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "termcaps.h"

void	cbuf_reset(t_memory *sh)
{
	if (sh->state == HGL)
		highlight_cleanup(sh, false, 0);
	if (sh->hst.browsing)
	{
		sh->hst.browsing = false;
		sh->hst.current = sh->hst.end;
		if (sh->hst.last_cmd)
			ft_strdel(&(sh->hst.last_cmd));
	}
	ft_bzero(sh->inp.cmd, sh->inp.cmdlen);
	ft_putstr(sh->inp.cbuf);
	sh->curs.x = PROMPT_SIZE;
	sh->curs.x_max = sh->curs.win_x - 1;
	sh->curs.y = 0;
	sh->curs.y_max = 0;
	sh->curs.i = PROMPT_SIZE;
	sh->inp.cbuflen = PROMPT_SIZE;
	sh->inp.cmdlen = 0;
	sh->inp.multi_line = false;
}
