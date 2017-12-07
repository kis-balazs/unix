/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tc_unset_canonical.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkis <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/07 13:47:22 by bkis              #+#    #+#             */
/*   Updated: 2017/07/07 13:47:22 by bkis             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "termcaps.h"

void	tc_unset_canonical(t_memory *sh)
{
	sh->term.c_lflag &= ~(ECHO | ICANON);
	sh->term.c_cc[VMIN] = 1;
	sh->term.c_cc[VTIME] = 0;
	if (tcsetattr(STDIN_FILENO, TCSADRAIN, &(sh->term)) < 0)
		sh_abort("cannot set terminal attributes");
}
