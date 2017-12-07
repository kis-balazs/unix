/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   an_ll.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkis <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/07 13:20:19 by bkis              #+#    #+#             */
/*   Updated: 2017/07/07 13:20:20 by bkis             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ast.h"

t_lexem			*find_op(t_st_lexem *statement)
{
	t_lexem		*ptr;
	t_lexem		*max;

	ptr = statement->begin_lexem;
	max = ptr;
	while (ptr)
	{
		if (max->priority <= ptr->priority)
			max = ptr;
		ptr = ptr->next;
	}
	return (max);
}

t_lexem			*find_prev_max(t_lexem *ptr)
{
	t_lexem		*max;
	t_lexem		*pcr;

	pcr = ptr;
	max = pcr;
	while (pcr != NULL)
	{
		if (max->priority < pcr->priority)
			max = pcr;
		pcr = pcr->prev;
	}
	if (max->priority == 0)
		max = rechatch_lexm(ptr);
	return (max);
}

t_lexem			*find_next_max(t_lexem *ptr)
{
	t_lexem		*max;
	t_lexem		*pcr;

	pcr = ptr;
	max = pcr;
	while (pcr != NULL)
	{
		if (max->priority < pcr->priority)
			max = pcr;
		pcr = pcr->next;
	}
	if (max->priority == 0)
		max = rechatch_lexm(ptr);
	return (max);
}
