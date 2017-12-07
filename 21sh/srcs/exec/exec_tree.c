/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_tree.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkis <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/07 13:24:25 by bkis              #+#    #+#             */
/*   Updated: 2017/07/07 13:24:26 by bkis             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

static const t_exec			g_exec[NB_TOKEN] =
{
	{OP_SP_LOG, logique_fonction},
	{OP_REDIR_RIGHT, redirection_fonction},
	{OP_REDIR_LEFT, redirection_fonction},
	{OP_PIPE, pipe_function},
	{VARIABLE, set_varible},
	{CMD, exec_fct},
};

void						exec_tree(t_node *ast, int *status)
{
	int						count;

	count = 0;
	while (g_exec[count].token != ast->body->lexem->token_type)
		count++;
	g_exec[count].f(ast, status);
}
