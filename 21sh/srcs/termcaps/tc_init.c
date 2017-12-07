/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tc_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkis <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/07 13:46:40 by bkis              #+#    #+#             */
/*   Updated: 2017/07/07 13:46:41 by bkis             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "termcaps.h"

void	tc_init(t_memory *sh)
{
	struct ttysize	ts;

	if (!isatty(STDIN_FILENO))
		sh_abort("not a tty");
	if (strncmp(ttyname(STDIN_FILENO), "/dev/", 5))
		sh_abort("invalid tty name");
	if (tgetent(NULL, getenv("TERM")) < 0)
		sh_abort("loading terminal entry failed");
	if (tcgetattr(STDIN_FILENO, &(sh->term)) < 0)
		sh_abort("cannot get terminal attributes");
	sh->term_d = sh->term;
	tc_unset_canonical(sh);
	sh->inp.maxlen = 1024;
	sh->inp.cbuf = (char *)ft_memalloc(sh->inp.maxlen);
	sh->inp.cmd = &(sh->inp.cbuf[PROMPT_SIZE]);
	sh->inp.cbuflen = PROMPT_SIZE;
	ft_strcpy(sh->inp.cbuf, PROMPT);
	if (ioctl(STDIN_FILENO, TIOCGWINSZ, &ts) < 0)
		sh_abort("cannot retrieve window size");
	sh->curs.win_x = ts.ts_cols;
	sh->curs.win_y = ts.ts_lines;
	sh->curs.x_max = ts.ts_cols - 1;
	sh->curs.x = PROMPT_SIZE;
	sh->curs.i = PROMPT_SIZE;
}
