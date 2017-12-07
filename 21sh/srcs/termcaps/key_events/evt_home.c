/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   evt_home.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkis <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/07 13:51:44 by bkis              #+#    #+#             */
/*   Updated: 2017/07/07 13:51:44 by bkis             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "termcaps.h"

void	evt_home(t_memory *sh)
{
	if (sh->curs.i == PROMPT_SIZE)
		return ;
	else if (sh->state == HGL)
	{
		sh->curs.i = PROMPT_SIZE;
		highlight(sh);
		return ;
	}
	sh->curs.i = PROMPT_SIZE;
	sh->curs.x = PROMPT_SIZE;
	if (sh->curs.y > 0)
	{
		tc_write("UP+", 0, sh->curs.y);
		sh->curs.y = 0;
	}
	tc_write("ch+", 0, PROMPT_SIZE);
}
