/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tool_lexem2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkis <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/07 13:45:30 by bkis              #+#    #+#             */
/*   Updated: 2017/07/07 13:45:30 by bkis             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer_parser.h"

t_lexem				*new_lexem(char *line)
{
	t_lexem			*new_lexem;

	new_lexem = (t_lexem*)ft_memalloc(sizeof(t_lexem));
	new_lexem->name_lexem = ft_strdup(line);
	new_lexem->next = NULL;
	new_lexem->prev = NULL;
	new_lexem->index = 0;
	new_lexem->option = NULL;
	new_lexem->token_type = define_token(new_lexem->name_lexem);
	new_lexem->priority = define_prio(new_lexem->token_type);
	return (new_lexem);
}
