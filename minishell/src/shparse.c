/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shparse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkis <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/15 16:26:17 by bkis              #+#    #+#             */
/*   Updated: 2017/05/15 16:26:18 by bkis             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void		envvars_replace(char **str, t_env_item *env)
{
	char	*value;

	if ((value = mgetenv(env, (*str) + 1)))
	{
		free(*str);
		*str = value;
	}
	else
	{
		free(*str);
		*str = ft_strdup("");
	}
}

int				shparse(char *line, t_shcmd *cmd, t_env_item *env)
{
	char	**splitted;
	int		c;

	c = 0;
	splitted = NULL;
	if (!(*(cmd->args = ft_strsplit(line, " \t"))))
		return (-1);
	cmd->cmd = cmd->args[0];
	while (cmd->args[c])
	{
		if (*(cmd->args[c]) == '$')
			envvars_replace(&(cmd->args[c]), env);
		c++;
	}
	return (cmd->args ? 1 : -1);
}
