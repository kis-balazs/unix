/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cb_paste_external.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkis <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/07 13:48:19 by bkis              #+#    #+#             */
/*   Updated: 2017/07/07 13:48:20 by bkis             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "termcaps.h"

static void	print_read_buffer(t_memory *sh, void (*f)(t_memory *, char))
{
	int	i;

	i = -1;
	while (sh->inp.rbuf[++i])
		ft_isprint(sh->inp.rbuf[i]) ? f(sh, sh->inp.rbuf[i]) : f(sh, ' ');
	ft_bzero(sh->inp.rbuf, sizeof(sh->inp.rbuf));
}

void		cb_paste_external(t_memory *sh)
{
	int		ret;
	void	(*f)(t_memory *, char);

	if (sh->curs.i < sh->inp.cbuflen)
		f = &cbuf_insert;
	else
		f = &cbuf_append;
	print_read_buffer(sh, f);
	tc_set_timed_read(sh);
	ret = RBUF_SIZE;
	while ((ret = read(STDIN_FILENO, sh->inp.rbuf, RBUF_SIZE)) > 0)
		print_read_buffer(sh, f);
	tc_set_blocking_read(sh);
}
