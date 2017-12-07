/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hst_browse_next.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkis <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/07 13:26:31 by bkis              #+#    #+#             */
/*   Updated: 2017/07/07 13:26:32 by bkis             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "termcaps.h"

void	hst_browse_next(t_memory *sh)
{
	if (sh->hst.current->next)
		sh->hst.current = sh->hst.current->next;
	else
		sh->hst.browsing = false;
	hst_update_cbuf(sh);
}
