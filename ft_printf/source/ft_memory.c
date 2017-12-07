/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memory.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkis <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/05 16:00:36 by bkis              #+#    #+#             */
/*   Updated: 2017/07/05 16:09:30 by bkis             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

PF		*ft_init_argument(PF *argument)
{
	int i;

	i = 0;
	while (i < 13)
	{
		argument->flags[i] = 0;
		i++;
	}
	argument->flags[0] = -1;
	argument->flags[1] = -1;
	argument->format = NULL;
	argument->index = 0;
	argument->spec = ' ';
	argument->arg = NULL;
	argument->warg = NULL;
	return (argument);
}

void	ft_init_spe_tab(SPE *spe)
{
	int i;

	i = 0;
	while (i < 128)
		spe->spe[i++] = ft_arg_nospe;
	spe->spe['p'] = pointer_handler;
	spe->spe['s'] = string_handler;
	spe->spe['S'] = string_handler;
	spe->spe['c'] = character_handler;
	spe->spe['C'] = character_handler;
	spe->spe['d'] = signed_handler;
	spe->spe['D'] = signed_handler;
	spe->spe['i'] = signed_handler;
	spe->spe['o'] = unsigned_handler;
	spe->spe['O'] = unsigned_handler;
	spe->spe['u'] = unsigned_handler;
	spe->spe['U'] = unsigned_handler;
	spe->spe['%'] = prc_handler;
	spe->spe['x'] = unsigned_handler;
	spe->spe['X'] = unsigned_handler;
	spe->spe['b'] = unsigned_handler;
}

void	ft_init_buff(void)
{
	int n;

	n = 0;
	while (n < BUFF_MAX)
	{
		g_buff[n] = '\0';
		n++;
	}
	g_i = 0;
}

int		ft_check_spec_bis(PF *argument)
{
	if (argument->format[argument->index] == 'c')
		argument->spec = 'c';
	else if (argument->format[argument->index] == 'C')
		argument->spec = 'C';
	else if (argument->format[argument->index] == 'F')
		argument->spec = 'F';
	else if (argument->format[argument->index] == 'f')
		argument->spec = 'f';
	else
		argument->spec = argument->format[argument->index];
	return (argument->index);
}
