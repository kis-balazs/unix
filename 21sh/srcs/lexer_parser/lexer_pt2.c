/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_pt2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkis <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/07 13:28:39 by bkis              #+#    #+#             */
/*   Updated: 2017/07/07 13:28:40 by bkis             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer_parser.h"

int				ctrl_heredoc(t_memory *memory, char *line)
{
	char		*tmp;

	tmp = NULL;
	memory->key_ctrl = ft_strndup(line, 0, (find_str(line)));
	if (line + (find_str(line)))
		memory->line_mode_after = ft_strdup(line + find_str(line));
	return (HEREDOC_CODE);
}

int				ctrl_quot(int first, int second)
{
	if (first == 34)
		return (D_QUOTE_CODE);
	else if (first == 39)
		return (QUOTE_CODE);
	else if (first == 96)
		return (BACKQUOTE_CODE);
	else if (first == '<' && second == '<' && g_memory.heredoc_sw == 0)
		return (HEREDOC_CODE);
	return (0);
}

int				ctrl_mode(char *line, t_memory *memory)
{
	int			count;
	int			tmp;

	tmp = 0;
	count = 0;
	if ((tmp = ctrl_quot(line[count], line[count + 1])) > 0)
	{
		count++;
		if (tmp == HEREDOC_CODE)
			return (ctrl_heredoc(memory, line + 3));
		while (line[count])
		{
			if (tmp == ctrl_quot(line[count], 0))
				return (count + 1);
			count++;
		}
		return (tmp);
	}
	return (0);
}

int				is_bulltin(char *cmd)
{
	if (ft_strcmp(cmd, "env") == 0
		|| ft_strcmp(cmd, "export") == 0
		|| ft_strcmp(cmd, "unsetenv") == 0
		|| ft_strcmp(cmd, "setenv") == 0
		|| ft_strcmp(cmd, "cd") == 0
		|| ft_strcmp(cmd, "exit") == 0
		|| ft_strcmp(cmd, "echo") == 0
		|| ft_strcmp(cmd, "history") == 0
		|| ft_strcmp(cmd, "var") == 0)
		return (1);
	return (0);
}
