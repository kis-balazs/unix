/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkis <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/07 13:29:04 by bkis              #+#    #+#             */
/*   Updated: 2017/07/07 13:29:05 by bkis             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer_parser.h"

int					define_prio(t_token token)
{
	if (token == CMD || token == ARG_FILES || token == OP_FILES ||
		token == VARIABLE)
		return (0);
	else if (token == OP_REDIR_LEFT)
		return (1);
	else if (token == OP_PIPE)
		return (2);
	else if (token == OP_REDIR_RIGHT)
		return (3);
	else if (token == OP_SP_LOG)
		return (4);
	return (-1);
}

int					token_rr(char *line)
{
	const char	*tableau[2];
	int			count;
	int			tmp;
	int			i;

	i = 0;
	count = 0;
	while (ft_isdigit(line[count]))
		count++;
	count += (line[count] == '&') ? 1 : 0;
	tableau[0] = ">>";
	tableau[1] = ">";
	if ((tmp = ctrl_tab(line + count, tableau, 2)) > 0)
		return (tmp + count);
	return (0);
}

int					token_left(char *line)
{
	const char	*tableau[2];
	int			count;
	int			tmp;
	int			i;

	i = 0;
	count = 0;
	while (ft_isdigit(line[count]))
		count++;
	count += (line[count] == '&') ? 1 : 0;
	tableau[0] = "<";
	tableau[1] = "<<";
	if ((tmp = ctrl_tab(line + count, tableau, 2)) > 0)
		return (tmp + count);
	return (0);
}

t_token				define_token(char *lexem)
{
	int				i;

	i = 0;
	if (token_rr(lexem))
		return (OP_REDIR_RIGHT);
	if (token_left(lexem))
		return (OP_REDIR_LEFT);
	if (!ft_strncmp(lexem, "&&", 2))
		return (OP_SP_LOG);
	if (!ft_strncmp(lexem, "||", 2))
		return (OP_SP_LOG);
	if (!ft_strncmp(lexem, "&", 1))
		return (OP_ASS);
	if (!ft_strncmp(lexem, "|", 1))
		return (OP_PIPE);
	if (!ft_strncmp(lexem, ";", 1))
		return (OP_SP_LOG);
	return (CMD);
}
