/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tc_set_blocking_read.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkis <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/07 13:47:07 by bkis              #+#    #+#             */
/*   Updated: 2017/07/07 13:47:08 by bkis             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "termcaps.h"

void	tc_set_blocking_read(t_memory *sh)
{
	sh->term.c_cc[VMIN] = 1;
	sh->term.c_cc[VTIME] = 0;
	if (tcsetattr(STDIN_FILENO, TCSADRAIN, &(sh->term)) < 0)
		sh_abort("cannot set terminal attributes");
}
