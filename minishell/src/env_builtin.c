/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_builtin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkis <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/15 16:24:03 by bkis              #+#    #+#             */
/*   Updated: 2017/05/15 16:24:09 by bkis             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int					env_fake_sort(t_list *t, t_list *n)
{
	(void)t;
	(void)n;
	return (1);
}

static t_env_item	*env_dup(t_env_item *env)
{
	t_env_item	*t;
	t_env_item	*tmp;
	t_env_item	*ne;

	if (!(t = env))
		return (NULL);
	ne = env_new_item(t->keyval, NULL, 1);
	while ((t = t->next))
	{
		tmp = env_new_item(t->keyval, NULL, 1);
		ft_lstappend((t_list*)ne, (t_list*)tmp);
	}
	return (ne);
}

static int			launch_cmd(t_env_item **e, t_env_item **new_e, char **av)
{
	char	*path;
	int		ret;
	t_shcmd	cmd;
	char	*cmd_path;

	cmd_path = NULL;
	cmd.cmd = *av;
	cmd.args = av;
	if (!(ret = builtins(&cmd, new_e)))
	{
		path = mgetenv(*e, "PATH");
		cmd_path = ft_strchr(*av, '/') ? ft_strdup(*av) : in_path(*av, path);
		if (cmd_path)
		{
			ret = forkexec(cmd_path, av, new_e);
			free(cmd_path);
			free(path);
		}
		ret = cmd_path ? ret : 127;
	}
	else
		ret--;
	return (ret);
}

int					menv(t_env_item **env, char **args)
{
	t_env_item	*new_env;
	int			ret;

	ret = 0;
	if (*args && !ft_strcmp(*args, "-i"))
	{
		new_env = NULL;
		args++;
	}
	else
		new_env = env_dup(*env);
	while (*args && ft_strchr(*args, '='))
		msetenv(&new_env, NULL, *args++, 1);
	if (*args)
		ret = launch_cmd(env, &new_env, args);
	else
		env_print(new_env);
	env_free(&new_env);
	return (ret);
}
