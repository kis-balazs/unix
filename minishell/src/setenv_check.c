/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setenv_check.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkis <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/15 16:25:55 by bkis              #+#    #+#             */
/*   Updated: 2017/05/15 16:26:11 by bkis             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		setenv_check(char *pair)
{
	char	*t;

	if (!(t = ft_strchr(pair, '=')))
	{
		ft_putendl_fd("minishell: WRONG PARAMETER", 2);
		return (1);
	}
	if (!*(t + 1))
	{
		ft_putendl_fd("minishell: WRONG PARAMETER", 2);
		return (1);
	}
	return (0);
}
