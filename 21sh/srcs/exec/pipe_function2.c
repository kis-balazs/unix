/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_function2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkis <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/07 13:24:58 by bkis              #+#    #+#             */
/*   Updated: 2017/07/07 13:24:59 by bkis             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

void					new_pid(t_pipe *pipe, pid_t pid)
{
	if (pid < 0)
		return ;
	if (pipe->list == NULL)
	{
		pipe->list = (pid_t*)malloc(sizeof(char*) * 2);
		pipe->list[0] = pid;
		pipe->list[1] = 0;
		pipe->count++;
	}
	else
	{
		MACREALLOC(pipe->list, pipe->list, ++pipe->count * sizeof(pid_t));
		pipe->list[pipe->count - 1] = pid;
	}
}

pid_t					verif_pid(t_pipe *pipe)
{
	if (pipe->count <= 0 || pipe->last + 1 >= pipe->count)
		return (-1);
	return (pipe->list[++pipe->last]);
}
