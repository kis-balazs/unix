/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ast.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkis <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/07 13:18:47 by bkis              #+#    #+#             */
/*   Updated: 2017/07/07 14:11:04 by bkis             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AST_H
# define AST_H

# include "lexer_parser.h"

# define RD 0
# define WRT 1

typedef struct s_body_node	t_body_node;

typedef	enum				e_type_node
{
	BEGIN,
	OP,
	LEAF,
}							t_type_node;

typedef struct				s_node
{
	t_body_node				*body;
	struct s_node			*parent;
	struct s_node			*left_op;
	struct s_node			*right_op;
}							t_node;

struct						s_body_node
{
	int						fd;
	pid_t					process;
	t_type_node				type_node;
	t_lexem					*lexem;
};

void						gestion_fd(t_node *ast);
t_node						*create_node(t_lexem *ptr, t_node **parent);
int							full_leaf(t_node **node, t_node **parent_node,
									t_node *new_node);
void						add_node(t_node	**node, t_node **parent_node,
									t_node *new_node);

t_lexem						*find_op(t_st_lexem *statement);
t_lexem						*find_prev_max(t_lexem *ptr);
t_lexem						*find_next_max(t_lexem *ptr);
void						exec_tree(t_node *ast, int *status);
t_lexem						*rechatch_lexm(t_lexem *ptr);

#endif
