/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   termcaps.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkis <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/07 13:47:35 by bkis              #+#    #+#             */
/*   Updated: 2017/07/07 13:47:36 by bkis             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "termcaps.h"
#include "shell.h"

void	termcaps(t_memory *sh)
{
	int		ret;

	while ((ret = read(STDIN_FILENO, sh->inp.rbuf, RBUF_SIZE)) > 0)
	{
		sh->signo ? sig_handler(sh) : evt_handler(sh);
		ft_bzero(sh->inp.rbuf, sizeof(sh->inp.rbuf));
		if (sh->inp.ready)
		{
			sh->line = sh->inp.cmd;
			sh->line_lenght = sh->inp.cmdlen;
			sh->inp.ready = false;
			break ;
		}
	}
}
