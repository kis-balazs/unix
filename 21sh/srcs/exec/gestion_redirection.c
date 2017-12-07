/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gestion_redirection.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkis <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/07 13:24:33 by bkis              #+#    #+#             */
/*   Updated: 2017/07/07 14:23:18 by bkis             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"
#include "termcaps.h"

void				close_fd_chain(int fd[4])
{
	if (fd[0] != 0 && fd[0] != 1 && fd[0] != 2 && fd[0] != -1)
		close(fd[0]);
	if (fd[1] != 0 && fd[1] != 1 && fd[1] != 2 && fd[1] != -1)
		close(fd[1]);
	if (fd[2] != 0 && fd[2] != 1 && fd[2] != 2 && fd[2] != -1)
		close(fd[2]);
	if (fd[3] != 0 && fd[3] != 1 && fd[3] != 2 && fd[3] != -1)
		close(fd[3]);
}

void				treat_redirection(t_node *ast, int fd[4], int *status)
{
	pid_t			pid;

	pid = fork();
	if (pid == -1)
		ft_putendl_fd("fork don't work", 2);
	if (!pid)
	{
		if (fd[0] && fd[2])
			dup2(fd[2], fd[0]);
		else if (fd[2])
			dup2(fd[2], fd[0]);
		else if (fd[1])
			dup2(fd[2], fd[1]);
		else if (fd[3])
		{
			dup2(fd[3], 1);
			dup2(fd[3], 2);
		}
		exec_tree(ast, status);
		exit(1);
	}
	close_fd_chain(fd);
	wait(&pid);
}

int					redirection_fonction(t_node *ast, int *status)
{
	t_list_fd		list_fd;
	int				value;

	if (ast->right_op != NULL)
		reacast_fd(ast->body->lexem->name_lexem,
					ast->right_op->body->lexem->name_lexem, &list_fd);
	else
		reacast_fd(ast->body->lexem->name_lexem, NULL, &list_fd);
	printf("%d %d %d %d\n", list_fd.fd[0],
			list_fd.fd[1], list_fd.fd[2], list_fd.fd[3]);
	if (ast->right_op &&
		(value = is_dir(ast->right_op->body->lexem->name_lexem)) != FILES)
	{
		if (value == REP)
			ft_putendl_fd("is a directory:", 2);
		else
			ft_putendl_fd("cannot redirect", 2);
	}
	else if (list_fd.fd[3] == -1)
		ft_putendl_fd("parse error near `'", 2);
	else
		treat_redirection(ast->left_op, list_fd.fd, status);
	return (0);
}
