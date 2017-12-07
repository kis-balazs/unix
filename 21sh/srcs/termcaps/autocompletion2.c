/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   autocompletion2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkis <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/07 13:46:17 by bkis              #+#    #+#             */
/*   Updated: 2017/07/07 13:46:18 by bkis             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "termcaps.h"
#include "shell.h"
#include "lexer_parser.h"

void				remove_autc(t_autocmp *autocmp)
{
	t_llist			*save;
	t_llist			*ptr;

	ptr = autocmp->match;
	while (ptr)
	{
		save = ptr;
		ptr = ptr->next;
		free(save->content);
		free(save);
	}
}

void				rsearch(char *str, char *trep, t_autocmp *autc)
{
	struct dirent	*files;
	DIR				*rep;

	autc->max_word = 0;
	if (!(rep = opendir(trep)))
		return ;
	while ((files = readdir(rep)) != NULL)
	{
		if (!ft_strncmp(str, files->d_name, ft_strlen(str)))
		{
			autc->occurance++;
			ft_lstadd(&(autc)->match, ft_lstnew(files->d_name,
						ft_strlen(files->d_name)));
		}
	}
	closedir(rep);
}

void				auto_push(char *str, t_memory *sh, int pos)
{
	while (str[pos])
	{
		cbuf_append(sh, str[pos]);
		pos++;
	}
}

void				aff_auto(t_autocmp *autocmpl, t_memory *sh)
{
	size_t			count;
	t_llist			*ptr;

	count = 0;
	ptr = autocmpl->match;
	tc_write("do");
	while (ptr)
	{
		ft_putstr(ptr->content);
		if (ptr->next != NULL)
			ft_putstr("  ");
		if (count >= sh->curs.win_y)
		{
			tc_write("do");
			count = 0;
		}
		count += ft_strlen(autocmpl->match->content);
		ptr = ptr->next;
	}
	tc_write("do");
	ft_putstr_fd(sh->inp.cbuf, STDERR_FILENO);
}
