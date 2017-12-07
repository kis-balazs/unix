/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   autocompletion.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkis <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/07 13:46:12 by bkis              #+#    #+#             */
/*   Updated: 2017/07/07 13:46:13 by bkis             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "termcaps.h"
#include "shell.h"
#include "lexer_parser.h"

void				sawfolder(t_memory *sh, char *path, t_autocmp *autc)
{
	struct dirent	*files;
	DIR				*rep;

	autc->max_word = 0;
	if (!(rep = opendir(path)))
		return ;
	while ((files = readdir(rep)) != NULL)
	{
		autc->occurance++;
		ft_lstadd(&(autc)->match, ft_lstnew(files->d_name,
					ft_strlen(files->d_name)));
	}
	if (sh->inp.cmd[sh->inp.cmdlen - 1] != '/')
		cbuf_append(sh, '/');
	closedir(rep);
}

void				folder_search(char *str, t_memory *sh, t_autocmp *autocmpl)
{
	char			*path;
	int				i;

	i = 0;
	path = NULL;
	if (is_dir(str) == REP)
		sawfolder(sh, str, autocmpl);
	else
	{
		if (!(path = search_env(g_env, "PWD=")))
			return ;
		rsearch(str, path, autocmpl);
	}
	if (autocmpl->occurance == 1)
		auto_push(autocmpl->match->content, sh, ft_strlen(str));
	else if (autocmpl->occurance > 1)
		aff_auto(autocmpl, sh);
}

void				binary_search(char *str, t_memory *sh, t_autocmp *autocmpl)
{
	int				lenght;
	char			**path;
	int				*tableau;
	int				i;

	i = 0;
	tableau = generate(58, 0, 2);
	lenght = ft_strsplit(&path, search_env(g_env, "PATH="), tableau);
	while (i < lenght - 1)
	{
		rsearch(str, path[i], autocmpl);
		i++;
	}
	if (autocmpl->occurance == 1)
		auto_push(autocmpl->match->content, sh, ft_strlen(str));
	else if (autocmpl->occurance > 1)
		aff_auto(autocmpl, sh);
	free(tableau);
	free_d(path, lenght);
	free(path);
}

static void			gestion_auto(t_autocmp *autocmpl, t_memory *sh, char **tmp2)
{
	if (autocmpl->lenght > 1 && ((!operator_filters(tmp2[autocmpl->lenght - 1])
		&& !redirection_filters(tmp2[autocmpl->lenght - 1]))))
		folder_search(tmp2[autocmpl->lenght - 1], sh, autocmpl);
	else
		binary_search(tmp2[autocmpl->lenght - 1], sh, autocmpl);
}

int					autocompletion(t_memory *sh)
{
	t_autocmp		autocmpl;
	char			**tmp2;
	int				*tableau;

	tmp2 = NULL;
	autocmpl.match = NULL;
	autocmpl.occurance = 0;
	if (!search_env(g_env, "PATH="))
		return (1);
	tableau = generate(9, 32, 3);
	if ((autocmpl.lenght = ft_strsplit(&tmp2, sh->inp.cmd, tableau)) > 0)
	{
		gestion_auto(&autocmpl, sh, tmp2);
		remove_autc(&autocmpl);
		free_d(tmp2, autocmpl.lenght);
		free(tmp2);
	}
	free(tableau);
	return (1);
}
