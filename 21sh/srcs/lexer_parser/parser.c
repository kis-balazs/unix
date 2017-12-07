/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkis <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/07 13:28:53 by bkis              #+#    #+#             */
/*   Updated: 2017/07/07 13:28:54 by bkis             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer_parser.h"

static int			parser(t_st_lexem **lex, t_memory *memory)
{
	int				count;
	int				pos;
	int				tmp;

	count = 0;
	while (count < memory->line_lenght)
	{
		tmp = 0;
		pos = count;
		if ((tmp = find_token(memory->line + pos)) > 0)
		{
			if (tmp > SWITCH_MODE)
				return (tmp);
			count += tmp;
			save_lexem(*lex, memory->line + pos, count, pos);
		}
		else if (memory->line[count] == ' ' || memory->line[count] == '\t')
			count++;
	}
	return (0);
}

static t_mode		mode_gestion(t_st_lexem *lexem, int code)
{
	stock_line(code);
	if (lexem->begin_lexem)
		free_lexem(lexem->begin_lexem);
	free(lexem);
	return (SHELL);
}

t_mode				lexer_parser(t_memory *memory)
{
	t_st_lexem		*lexem;
	int				code_mode;

	code_mode = 0;
	lexem = (t_st_lexem*)ft_memalloc(sizeof(t_st_lexem));
	if ((code_mode = parser(&lexem, memory)) > SWITCH_MODE)
		return (mode_gestion(lexem, code_mode));
	if (lexem->begin_lexem)
	{
		generate_ast(lexem);
		free(lexem);
	}
	return (SHELL);
}
