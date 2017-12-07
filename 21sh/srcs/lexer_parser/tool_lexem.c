/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tool_lexem.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkis <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/07 13:45:22 by bkis              #+#    #+#             */
/*   Updated: 2017/07/07 13:45:25 by bkis             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer_parser.h"

int					recall_q(char **str, char *line)
{
	char			*tmp;
	char			*tmp2;
	int				count;

	count = 0;
	tmp = NULL;
	tmp2 = NULL;
	while (line[count] && (line[count] != '\'' && line[count] != '\"'))
		count++;
	if (*str == NULL)
		*str = ft_strndup(line, 0, count);
	else
	{
		tmp = ft_strndup(line, 0, count);
		tmp2 = ft_strjoin(*str, tmp);
		free(*str);
		free(tmp);
		*str = tmp2;
	}
	if (line[count] == '\'')
		epur_str(str, 2);
	else
		epur_str(str, 1);
	return (count);
}

int					recall_ob(char **str, char *line)
{
	char			*tmp;
	char			*tmp2;
	int				count;

	count = 0;
	tmp = NULL;
	tmp2 = NULL;
	while (line[count] && (line[count] != '\'' && line[count] != '\"'))
		count++;
	if (*str == NULL)
		*str = ft_strndup(line, 0, count);
	else
	{
		tmp = ft_strndup(line, 0, count);
		tmp2 = ft_strjoin(*str, tmp);
		free(*str);
		free(tmp);
		*str = tmp2;
	}
	epur_str(str, 0);
	return (count);
}

char				*define_name_lexem(char *line)
{
	char			*str;
	int				count;
	int				mode;

	mode = 0;
	count = 0;
	str = NULL;
	while (line[count])
	{
		if ((line[count] == '\'' || line[count] == '\"'))
		{
			if (mode == 1)
				mode = 0;
			else if (mode == 0)
				mode = 1;
			count++;
		}
		if (mode == 1)
			count += recall_q(&str, line + count);
		if (mode == 0)
			count += recall_ob(&str, line + count);
		if (!line[count + 1] || !line[count])
			return (str);
	}
	return (str);
}

void				free_lexem(t_lexem *lexem)
{
	free(lexem->name_lexem);
	free_d(lexem->option, lexem->index);
	free(lexem->option);
	lexem->priority = 0;
	free(lexem);
}

void				clear_lexem(t_lexem *lexem, t_st_lexem *lex)
{
	if (lexem->next == NULL && lexem->prev == NULL)
	{
		lex->begin_lexem = NULL;
		lex->end_lexem = NULL;
	}
	else if (lexem->prev == NULL)
	{
		lexem->next->prev = NULL;
		lex->begin_lexem = lexem->next;
	}
	else if (lexem->next == NULL)
	{
		lexem->prev->next = NULL;
		lex->end_lexem = lexem->prev;
	}
	else
	{
		lexem->prev->next = lexem->next;
		lexem->next->prev = lexem->prev;
	}
	free_lexem(lexem);
}
