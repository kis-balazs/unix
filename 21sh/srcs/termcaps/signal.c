/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkis <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/07 13:46:30 by bkis              #+#    #+#             */
/*   Updated: 2017/07/07 13:46:30 by bkis             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "termcaps.h"

void	sig_set(int signo)
{
	g_memory.signo = signo;
	ioctl(STDIN_FILENO, TIOCSTI, "");
}

void	sig_init(void)
{
	signal(SIGWINCH, &sig_set);
	signal(SIGINT, &sig_set);
}

void	sig_handler(t_memory *sh)
{
	if (sh->signo == SIGINT)
	{
		ft_putchar('\n');
		cbuf_reset(sh);
	}
	else if (sh->signo == SIGWINCH)
		tc_refresh(sh);
	sh->signo = 0;
}
