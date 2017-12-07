/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hst_tmp_push.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkis <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/07 13:27:17 by bkis              #+#    #+#             */
/*   Updated: 2017/07/07 13:27:18 by bkis             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "termcaps.h"

void	hst_tmp_push(t_memory *sh)
{
	t_hlst	*node;

	node = (t_hlst *)ft_memalloc(sizeof(t_hlst));
	node->cmd = ft_strdup(sh->inp.cmd);
	node->cmdlen = sh->inp.cmdlen;
	if (sh->hst.tmphead == NULL)
		sh->hst.tmphead = node;
	if (!sh->hst.head)
		sh->hst.head = node;
	else
	{
		sh->hst.current = sh->hst.end;
		node->prev = sh->hst.current;
		sh->hst.current->next = node;
	}
	sh->hst.current = node;
	sh->hst.end = node;
}
