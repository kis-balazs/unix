/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_parser.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkis <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/07 13:19:00 by bkis              #+#    #+#             */
/*   Updated: 2017/07/07 14:11:16 by bkis             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEXER_PARSER_H
# define LEXER_PARSER_H

# include "shell.h"

typedef enum			e_token
{
	OP_SP_LOG,
	OP_ASS,
	OP_REDIR_RIGHT,
	OP_REDIR_LEFT,
	OP_PIPE,
	OP_FILES,
	VARIABLE,
	CMD,
	ARG_FILES,
}						t_token;

typedef struct			s_lexem
{
	t_token				token_type;
	char				**option;
	char				*name_lexem;
	int					index;
	int					priority;
	struct s_lexem		*next;
	struct s_lexem		*prev;
}						t_lexem;

typedef struct			s_st_lexem
{
	t_lexem				*pos;
	int					nb_of_lexem;
	int					fd_count;
	struct s_lexem		*save;
	struct s_lexem		*begin_lexem;
	struct s_lexem		*end_lexem;
}						t_st_lexem;

t_lexem					*new_lexem(char *line);
void					save_lexem(t_st_lexem *lex, char *line, int end,
									int begin);
void					clear_lexem(t_lexem *lexem, t_st_lexem *lex);
void					free_lexem(t_lexem *lexem);
t_lexem					*cpy_lexem(t_lexem *to_cpy);
void					push_lexem(t_st_lexem *lex, t_lexem *new);

int						define_prio(t_token token);
t_token					define_token(char *lexem);

void					redi_lexem(t_st_lexem *lex, char *tmp, t_lexem *new);
void					arg_spe_sep(t_st_lexem *lex, char *line);
void					arg_files(t_st_lexem *lex);

void					generate_ast(t_st_lexem *lex);

int						redirection_filters(char *line);
int						find_token(char *line);
int						ctrl_tab(char *line, const char **tableau, int itr);
int						ctrl_tab2(int count, char *line);
char					*define_name_lexem(char *line);
void					epur_str(char **str, int mode);
void					stock_line(int code_mode);

#endif
