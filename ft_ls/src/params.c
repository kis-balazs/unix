/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   params.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkis <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/08 18:43:16 by bkis              #+#    #+#             */
/*   Updated: 2017/03/11 13:18:10 by bkis             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void	err_exit(char c)
{
	ft_putstr("Error : ");
	ft_putchar(c);
	ft_putstr(": ");
	ft_putendl(strerror(22));
	exit(EXIT_FAILURE);
}

t_params	parse_args(char const *av)
{
	t_params			opts;
	unsigned short int	err;

	err = 0;
	opts = 0;
	while (*av)
	{
		*av == 'l' ? opts |= LONG_FORMAT : err++;
		*av == 'r' ? opts |= REV_SORT : err++;
		*av == 'R' ? opts |= RECURSIVE : err++;
		*av == 'a' ? opts |= ALL : err++;
		*av == 't' ? opts |= TIME_SORT : err++;
		*av == 'A' ? opts |= ALMOST_ALL : err++;
		*av == 'g' ? opts |= HIDE_OWNER | LONG_FORMAT : err++;
		*av == 'F' ? opts |= ADD_FTYPE : err++;
		*av == 'B' ? opts |= FULL_NAMES : err++;
		*av == '1' ? 0 : err++;
		err != 9 ? err_exit(*av) : (err = 0);
		av++;
	}
	return (opts);
}
