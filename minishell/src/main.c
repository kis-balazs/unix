/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkis <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/15 16:24:38 by bkis              #+#    #+#             */
/*   Updated: 2017/05/15 16:25:16 by bkis             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int		shell_init(t_env_item **env)
{
	char	*pwd;
	char	*t;
	char	*shlvl;

	if (!*env)
		msetenv(env, NULL, "PATH=/usr/bin:/bin:/usr/sbin:/sbin", 1);
	if (!(pwd = malloc(sizeof(char) * PATH_MAX)))
		return (-1);
	if (!(pwd = getcwd(pwd, PATH_MAX)))
		myexit(env, "10", "minishell: START IN WRONG DIRECTORY");
	msetenv(env, NULL, (t = ft_strjoin("PWD=", pwd)), 1);
	free(t);
	free(pwd);
	if ((shlvl = mgetenv(*env, "SHLVL")))
	{
		t = ft_itoa(ft_atoi(shlvl) + 1);
		free(shlvl);
		msetenv(env, NULL, (shlvl = ft_strjoin("SHLVL=", t)), 1);
		free(shlvl);
		free(t);
	}
	return (0);
}

int				main(int ac, char **av, char **environ)
{
	t_env_item	*env;

	(void)ac;
	(void)av;
	env = NULL;
	if (*environ)
	{
		if (env_populate(&env, environ) < 0)
		{
			ft_putendl_fd("minishell: ERROR READING ENVIRON", 2);
			return (-1);
		}
	}
	else
		env = NULL;
	shell_init(&env);
	shell_loop(&env);
	env_free(&env);
	return (EXIT_SUCCESS);
}

void			shell_loop(t_env_item **env)
{
	char	*line;
	t_shcmd	cmd;
	int		gnl_ret;
	int		ret;

	ret = 0;
	while (1)
	{
		sp_prompt(*env, ret);
		if ((gnl_ret = get_next_line(1, &line)) < 0)
			myexit(env, "-1", "Input hiba");
		else if (!gnl_ret)
			break ;
		else
		{
			if (*line && (shparse(line, &cmd, *env) > 0))
					ret = exec_cmd(&cmd, env);
			ft_strdel(&line);
		}
	}
}
