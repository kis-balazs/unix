/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_gestion.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkis <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/07 13:22:42 by bkis              #+#    #+#             */
/*   Updated: 2017/07/07 13:22:43 by bkis             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"
#include "termcaps.h"

static int			check_builltins_tris(char **cmd)
{
	if (!ft_strcmp(cmd[0], "export"))
	{
		ft_export(cmd[1]);
		return (1);
	}
	return (0);
}

static int			check_builltins_bis(char **cmd)
{
	if (!ft_strcmp(cmd[0], "unsetenv") && cmd[1])
	{
		ft_unsetenv(cmd);
		return (1);
	}
	else if (!ft_strncmp(cmd[0], "echo", 4))
	{
		ft_echo(cmd);
		return (1);
	}
	else if (!ft_strcmp(cmd[0], "setenv"))
	{
		ft_setenv(cmd[1], cmd[2]);
		return (1);
	}
	else if (!ft_strcmp(cmd[0], "history"))
	{
		history(cmd);
		return (1);
	}
	return (check_builltins_tris(cmd));
}

static int			check_builltins(char **cmd, int index)
{
	if (cmd[0] == '\0')
		return (1);
	else if (!ft_strcmp(cmd[0], "env"))
	{
		print_env();
		return (1);
	}
	else if (!ft_strcmp(cmd[0], "cd"))
	{
		ft_cd(cmd, index);
		return (1);
	}
	else if (!ft_strcmp(cmd[0], "pwd"))
	{
		ft_putendl(get_pwd());
		return (1);
	}
	else if (!ft_strcmp(cmd[0], "exit"))
	{
		tc_restore_default(&g_memory);
		ft_putendl_fd("exit_is_ok", 1);
		exit(0);
	}
	else
		return (check_builltins_bis(cmd));
}

void				exec_fct2(t_lexem *lexem, pid_t child)
{
	char			**env;

	if (!(check_builltins(lexem->option, lexem->index)))
	{
		child = fork();
		if (!child)
		{
			env = copy_env();
			execve(lexem->option[0], lexem->option, env);
			free_d(env, g_memory.env_lenght);
			free(env);
			exit(1);
		}
		else if (child < 0)
			ft_putendl_fd("Fork Error", 2);
		else
			wait(0);
	}
}

int					exec_fct(t_node *ast, int *status)
{
	pid_t			child_pid;
	int				pos;

	pos = 1;
	child_pid = 0;
	if (ast && (find_command(&ast->body->lexem->option[0])) > 0)
		exec_fct2(ast->body->lexem, child_pid);
	else
	{
		*status = 1;
		return (-1);
	}
	*status = 0;
	return (0);
}
