/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkis <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/15 16:23:45 by bkis              #+#    #+#             */
/*   Updated: 2017/05/15 16:23:58 by bkis             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int			forkexec(char *cmd, char **av, t_env_item **env)
{
	pid_t	father;
	char	**tmp_env;
	int		ret_value;

	ret_value = 0;
	if ((father = fork()) < 0)
		exit(EXIT_FAILURE);
	if (!father)
	{
		tmp_env = env_to_table(*env);
		if ((execve(cmd, av, tmp_env)))
			exit(EXIT_FAILURE);
	}
	waitpid(father, &ret_value, 0);
	return (WEXITSTATUS(ret_value));
}

static int	exc(t_env_item **env, t_shcmd *cmd)
{
	int		ret;
	char	*path;
	char	*f;

	f = NULL;
	path = mgetenv(*env, "PATH");
	if (path && ((ft_strchr(cmd->cmd, '/') && (f = ft_strdup(cmd->cmd)))
				|| (f = in_path(cmd->cmd, path))))
		ret = forkexec(f, cmd->args, env);
	else
	{
		ret = 127;
		ft_putstr("minishell: UNKNOWN COMMAND: ");
		ft_putendl(cmd->cmd);
	}
	if (path)
		free(path);
	if (f)
		free(f);
	return (ret);
}

int			exec_cmd(t_shcmd *cmd, t_env_item **env)
{
	int			ret;
	char		*rval;
	char		*rtxt;

	if (!(ret = builtins(cmd, env)))
		ret = exc(env, cmd);
	else
		ret--;
	rval = ft_itoa(ret);
	if (cmd->args)
		ft_strtdel(&cmd->args);
	msetenv(env, NULL, (rtxt = ft_strjoin("?=", rval)), 1);
	free(rval);
	free(rtxt);
	return (ret);
}
