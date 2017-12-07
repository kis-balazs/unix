/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_builltin2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkis <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/07 13:21:53 by bkis              #+#    #+#             */
/*   Updated: 2017/07/07 13:21:54 by bkis             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

t_code				ctrl_arg(char **cmd, int *pos)
{
	int				test;

	test = 0;
	while (cmd[*pos])
	{
		if (cmd[*pos][0] != '-')
		{
			test = is_dir(cmd[*pos]);
			if (test != FILES && test != REP)
			{
				ft_putstr_fd("shell: No such file or directory: ", 2);
				ft_putendl_fd(cmd[*pos], 2);
				return (CD_FILES);
			}
		}
		*pos += 1;
	}
	return (NONE);
}
