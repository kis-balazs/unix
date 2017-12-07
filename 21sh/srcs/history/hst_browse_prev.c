/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hst_browse_prev.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkis <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/07 13:26:43 by bkis              #+#    #+#             */
/*   Updated: 2017/07/07 13:26:44 by bkis             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "termcaps.h"

void	hst_browse_prev(t_memory *sh)
{
	if (!sh->hst.browsing)
	{
		sh->hst.browsing = true;
		if (sh->inp.cmdlen > 0)
		{
			sh->hst.last_cmd = ft_strdup(sh->inp.cmd);
			sh->hst.last_cmdlen = sh->inp.cmdlen;
		}
	}
	else if (sh->hst.current->prev)
		sh->hst.current = sh->hst.current->prev;
	else
		return ;
	hst_update_cbuf(sh);
}
