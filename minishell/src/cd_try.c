/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd_try.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkis <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/15 16:23:06 by bkis              #+#    #+#             */
/*   Updated: 2017/05/15 16:23:38 by bkis             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int			try_dir(char *dir, char *arg)
{
	int	ret;

	if (access(dir, X_OK))
	{
		if (access(dir, F_OK))
		{
			ft_putstr_fd("minishell: NO FOLDER: ", 2);
			ft_putendl_fd(arg, 2);
		}
		else
		{
			ft_putstr_fd("minishell: NO RIGHTS FOR FOLDER: ", 2);
			ft_putendl_fd(arg, 2);
		}
		return (2);
	}
	else if ((ret = chdir(dir)))
	{
		ft_putstr_fd("minishell: UNKNOWN ERROR FOR FOLDER: ", 2);
		ft_putendl_fd(arg, 2);
		return (ret);
	}
	return (0);
}
