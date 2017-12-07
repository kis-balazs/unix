/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   log_sep.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkis <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/07 13:24:40 by bkis              #+#    #+#             */
/*   Updated: 2017/07/07 13:24:41 by bkis             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

void			exec_fonc_and(t_node *ast, int *status)
{
	if (*status == 0)
	{
		if (ast->left_op == NULL)
		{
			ft_putendl_fd("21sh: syntax error near unexpected token `&&'", 2);
			*status = 1;
		}
		else
			exec_tree(ast->left_op, status);
	}
	if (*status == 0)
	{
		if (ast->right_op == NULL)
		{
			ft_putendl_fd("21sh: syntax error near unexpected token `&&'", 2);
			*status = 1;
		}
		else
			exec_tree(ast->right_op, status);
	}
}

void			exec_fonc_sep(t_node *ast, int *status)
{
	int			tmp;

	tmp = 0;
	if (ast->left_op == NULL)
		ft_putendl_fd("syntax error near unexpected token `;\'", 2);
	else
		exec_tree(ast->left_op, &tmp);
	if (ast->right_op != NULL)
		exec_tree(ast->right_op, status);
	if (tmp == 1 && *status == 1)
		*status = 1;
	else
		*status = 0;
}

void			exec_fonc_or(t_node *ast, int *status)
{
	if (*status == 0)
	{
		if (ast->left_op == NULL)
		{
			ft_putendl_fd("21sh: syntax error near unexpected token `&&'", 2);
			*status = 1;
		}
		else
			exec_tree(ast->left_op, status);
	}
	if (*status == 1)
	{
		if (ast->right_op == NULL)
			ft_putendl_fd("21sh: syntax error near unexpected token `&&'", 2);
		else
			exec_tree(ast->right_op, status);
	}
}

int				logique_fonction(t_node *ast, int *status)
{
	if (!(ft_strcmp(ast->body->lexem->name_lexem, "&&")))
		exec_fonc_and(ast, status);
	if (!(ft_strcmp(ast->body->lexem->name_lexem, ";")))
		exec_fonc_sep(ast, status);
	if (!(ft_strcmp(ast->body->lexem->name_lexem, "||")))
		exec_fonc_or(ast, status);
	return (0);
}
