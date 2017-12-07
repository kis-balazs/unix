/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkis <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/15 16:22:59 by bkis              #+#    #+#             */
/*   Updated: 2017/05/15 16:23:00 by bkis             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int			builtins(t_shcmd *cmd, t_env_item **env)
{
	char	*tmp;
	int		ret;

	ret = 0;
	tmp = NULL;
	if (!ft_strcmp(cmd->cmd, "cd"))
		ret = bi_cd(cmd->args, *env);
	else if (!ft_strcmp(cmd->cmd, "env"))
		ret = menv(env, cmd->args + 1);
	else if (!ft_strcmp(cmd->cmd, "unsetenv"))
		ret = munsetenv(env, cmd->args[1]);
	else if (!ft_strcmp(cmd->cmd, "setenv"))
		ret = msetenv(env, NULL, cmd->args[1], 1);
	else if (!ft_strcmp(cmd->cmd, "exit"))
		myexit(env, cmd->args[1] ? cmd->args[1] : "0", NULL);
	else if (!ft_strcmp(cmd->cmd, "pwd"))
		ft_putendl((tmp = mgetenv(*env, "PWD")));
	else if (!ft_strcmp(cmd->cmd, "echo"))
		bi_echo(cmd->args + 1);
	else
		return (0);
	if (tmp)
		free(tmp);
	return (ret + 1);
}

void		bi_echo(char **args)
{
	int		c;

	c = 0;
	while (args[c])
	{
		ft_putstr(args[c]);
		ft_putchar(' ');
		c++;
	}
	ft_putchar('\n');
}
