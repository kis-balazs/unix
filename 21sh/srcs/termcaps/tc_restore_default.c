/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tc_restore_default.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkis <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/07 13:46:57 by bkis              #+#    #+#             */
/*   Updated: 2017/07/07 13:46:58 by bkis             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "termcaps.h"

void	tc_restore_default(t_memory *sh)
{
	if (tcsetattr(STDIN_FILENO, TCSAFLUSH, &(sh->term_d)) < 0)
		sh_abort("cannot set terminal attributes");
}
