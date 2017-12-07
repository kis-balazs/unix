/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   myexit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkis <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/15 16:25:23 by bkis              #+#    #+#             */
/*   Updated: 2017/05/15 16:25:24 by bkis             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	myexit(t_env_item **env, char *nu, char *msg)
{
	int errnum;
	int n;

	errnum = ft_atoi(nu);
	n = 0;
	if (msg)
		ft_putendl(msg);
	env_free(env);
	exit(n ? n : errnum);
}
