/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_function.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkis <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/07 13:24:50 by bkis              #+#    #+#             */
/*   Updated: 2017/07/07 13:24:51 by bkis             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

static int			g_stat;

static void			wait_pipe(t_pipe *pipe, int ret)
{
	pid_t			pid;
	int				id;

	if (!ret)
	{
		pid = verif_pid(pipe);
		waitpid(pid, &id, 0);
		id = WEXITSTATUS(id);
		g_stat = WEXITSTATUS(id);
	}
	while ((pid = verif_pid(pipe)) != -1)
	{
		kill(pid, SIGPIPE);
		waitpid(pid, &id, 0);
		id = WEXITSTATUS(id);
	}
}

pid_t				exec_l(t_pipe *pipe, t_node *left, int fd[2], int *status)
{
	pid_t			pid;

	pid = fork();
	if (pid == -1)
		return (-1);
	if (pid)
	{
		close(fd[1]);
		new_pid(pipe, pid);
		return (pid);
	}
	dup2(fd[1], STDOUT_FILENO);
	close(fd[0]);
	if (left->body->lexem->token_type == CMD)
		exec_fct(left, status);
	else
		exec_tree(left, status);
	exit(g_stat);
	return (pid);
}

pid_t				exec_r(t_pipe *pipe, t_node *right, int fd[2], int *status)
{
	pid_t			pid;

	pid = fork();
	if (pid == -1)
		return (-1);
	if (pid)
	{
		close(fd[0]);
		new_pid(pipe, pid);
		return (pid);
	}
	dup2(fd[0], STDIN_FILENO);
	close(fd[1]);
	if (right->body->lexem->token_type == CMD)
		exec_fct(right, status);
	else
		exec_tree(right, status);
	exit(g_stat);
	return (pid);
}

static int			exec_pipe(t_pipe *p, t_node *ast, int *status)
{
	int				fd[2];
	int				save;
	int				ret;
	pid_t			pid;

	if (pipe(fd))
		return (0);
	if ((pid = exec_r(p, ast->right_op, fd, status) < 0))
		return (1);
	if (ast->left_op->body->lexem->token_type == OP_PIPE)
	{
		save = dup(STDOUT_FILENO);
		dup2(fd[1], STDOUT_FILENO);
		close(fd[1]);
		ret = exec_pipe(p, ast->left_op, status);
		dup2(save, STDOUT_FILENO);
		close(save);
		return (ret);
	}
	if ((exec_l(p, ast->left_op, fd, status)) < 0)
		return (0);
	return (1);
}

int					pipe_function(t_node *ast, int *status)
{
	t_pipe			pipe;
	int				ret;

	pipe.count = 0;
	pipe.last = -1;
	pipe.list = NULL;
	if (!(ret = exec_pipe(&pipe, ast, status)))
	{
		*status = 1;
		ft_putendl_fd("Error Pipe", 2);
	}
	wait_pipe(&pipe, !ret);
	free(pipe.list);
	return (ret);
}
