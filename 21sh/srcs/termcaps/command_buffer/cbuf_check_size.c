/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cbuf_check_size.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkis <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/07 13:48:48 by bkis              #+#    #+#             */
/*   Updated: 2017/07/07 13:48:49 by bkis             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "termcaps.h"

void	cbuf_check_size(t_memory *sh, size_t len)
{
	char	*cbuf;

	if ((sh->inp.cbuflen + len) < sh->inp.maxlen)
		return ;
	while ((sh->inp.cbuflen + len) >= sh->inp.maxlen)
		sh->inp.maxlen += 1024;
	cbuf = (char *)ft_memalloc(sh->inp.maxlen);
	ft_memcpy(cbuf, sh->inp.cbuf, sh->inp.cbuflen);
	free(sh->inp.cbuf);
	sh->inp.cbuf = cbuf;
	sh->inp.cmd = &(cbuf[PROMPT_SIZE]);
}
