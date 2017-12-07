/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkis <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/07 13:28:30 by bkis              #+#    #+#             */
/*   Updated: 2017/07/07 13:28:31 by bkis             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer_parser.h"

int				operator_filters(char *line)
{
	const char	*tableau[5];
	int			i;

	i = 0;
	tableau[0] = "&&";
	tableau[1] = "||";
	tableau[2] = "&";
	tableau[3] = "|";
	tableau[4] = ";";
	while (i < 5)
	{
		if (!ft_strncmp(tableau[i], line, ft_strlen(tableau[i])))
			return (ft_strlen(tableau[i]));
		i++;
	}
	return (0);
}

int				redirection_filters(char *line)
{
	const char	*tableau[4];
	int			count;
	int			tmp;

	tmp = 0;
	count = 0;
	tableau[0] = ">>";
	tableau[1] = "<<";
	tableau[2] = ">";
	tableau[3] = "<";
	while (ft_isdigit(line[count]))
		count++;
	if (count > 1)
		return (0);
	count += (line[count] == '&') ? 1 : 0;
	if ((tmp = ctrl_tab(line + count, tableau, 4)) > 0)
		return (tmp + count);
	return (0);
}

int				find_str(char *line)
{
	int			count;
	int			itr;

	itr = 0;
	count = 0;
	while ((line[count]) && ((line[count] != ' ') || (line[count - 1] == '\\')))
	{
		if ((operator_filters(line + count)) > 0)
			return (count);
		else if ((redirection_filters(line + count)) > 0)
			return (count);
		else if ((itr = ctrl_mode(line + count, &g_memory)) > 0)
			return (itr + 2);
		else
			count++;
	}
	return (count);
}

int				find_token(char *line)
{
	int			tmp;
	int			iter;

	tmp = 0;
	iter = 0;
	if ((tmp = redirection_filters(line)) > 0)
		return (tmp);
	if ((tmp = ctrl_mode(line, &g_memory)) > 0)
		return (tmp);
	if ((tmp = operator_filters(line)) > 0)
		return (tmp);
	if ((tmp = find_str(line)) > 0)
		return (tmp);
	return (tmp);
}
