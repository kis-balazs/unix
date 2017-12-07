/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexem_pt2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkis <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/07 13:28:21 by bkis              #+#    #+#             */
/*   Updated: 2017/07/07 13:28:22 by bkis             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer_parser.h"

void				arg_spe_sep(t_st_lexem *lex, char *line)
{
	t_lexem			*arg_files;

	arg_files = (t_lexem*)ft_memalloc(sizeof(t_lexem));
	arg_files->name_lexem = ft_strdup(line);
	arg_files->next = NULL;
	arg_files->prev = NULL;
	arg_files->index = 0;
	arg_files->option = NULL;
	arg_files->token_type = OP_SP_LOG;
	arg_files->priority = define_prio(arg_files->token_type);
	push_lexem(lex, arg_files);
}
