/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tc_set_timed_read.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkis <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/07 13:47:15 by bkis              #+#    #+#             */
/*   Updated: 2017/07/07 13:47:16 by bkis             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "termcaps.h"

void	tc_set_timed_read(t_memory *sh)
{
	sh->term.c_cc[VMIN] = 0;
	sh->term.c_cc[VTIME] = 1;
	if (tcsetattr(STDIN_FILENO, TCSADRAIN, &(sh->term)) < 0)
		sh_abort("cannot set terminal attributes");
}
