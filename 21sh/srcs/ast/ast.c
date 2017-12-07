/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ast.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkis <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/07 13:20:26 by bkis              #+#    #+#             */
/*   Updated: 2017/07/07 13:20:26 by bkis             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ast.h"

void		free_ast(t_node *ast)
{
	if (ast == NULL)
		return ;
	free_ast(ast->left_op);
	free_ast(ast->right_op);
	free_lexem(ast->body->lexem);
	free(ast->body);
	free(ast);
}

void		create(t_node **parent, t_node **ast, t_lexem *pos, t_st_lexem *lex)
{
	t_lexem	*prev;
	t_lexem	*next;

	prev = NULL;
	next = NULL;
	if (pos->next)
		next = find_next_max(pos->next);
	if (pos->prev)
		prev = find_prev_max(pos->prev);
	if (next && next->priority > 0)
	{
		pos->next->prev = NULL;
		pos->next = NULL;
	}
	if (*ast == NULL)
	{
		*ast = create_node(pos, parent);
		if (next != NULL)
			create(&(*ast), &(*ast)->right_op, next, lex);
		if (prev != NULL)
			create(&(*ast), &(*ast)->left_op, prev, lex);
	}
}

void		generate_ast(t_st_lexem *lex)
{
	t_node	*ast;
	t_lexem	*begin;
	int		status;

	ast = NULL;
	status = 0;
	begin = find_op(lex);
	create(NULL, &ast, begin, lex);
	exec_tree(ast, &status);
	free_ast(ast);
}
