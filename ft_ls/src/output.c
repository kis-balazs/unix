/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkis <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/08 18:42:58 by bkis              #+#    #+#             */
/*   Updated: 2017/03/11 13:38:55 by bkis             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_files				*rev_print_slist(t_files *node)
{
	t_files *tmp;
	int		bc;
	int		nc;

	bc = 0;
	nc = 0;
	tmp = node;
	while (tmp)
	{
		if (!tmp->subfiles && !tmp->fcount)
		{
			st_fputstr(tmp->details, tmp->fields_len);
			nc++;
		}
		else
			bc++;
		tmp = (t_files*)tmp->prev;
	}
	if (bc && nc)
		ft_putendl("");
	return (node);
}

static inline void	print_dirname(t_files *dir, t_params opts)
{
	int static nb;

	nb = 0;

	if (nb || dir->prev)
		ft_putchar('\n');
	if (dir->next || dir->prev || (opts & RECURSIVE && nb))
	{
		ft_putstr(dir->name);
		ft_putstr(":\n");
	}
	nb++;
	if (opts & LONG_FORMAT && dir->subfiles)
	{
		ft_putstr("total ");
		ft_putnbr(dir->fcount > 0 ? ++dir->fcount : 0);
		ft_putchar('\n');
	}
}

void				rev_recurse_out(t_files *root, t_params opts)
{
	t_files	*tmp;

	tmp = lastnode(root->subfiles);
	if (root->subfiles || (root->fcount && (root->next || root->prev)))
		print_dirname(root, opts);
	while (tmp)
	{
		st_fputstr(tmp->details, root->fields_len);
		tmp = (t_files*)tmp->prev;
	}
	if (opts & RECURSIVE)
	{
		tmp = lastnode(root->subfiles);
		while (tmp)
		{
			if (tmp->fcount && !ft_strstr(tmp->name, "/..") &&
					ft_strcmp(".", epure_name(tmp->name, opts)))
				rev_recurse_out(tmp, opts);
			tmp = (t_files*)tmp->prev;
		}
	}
}

void				recurse_out(t_files *root, t_params opts)
{
	t_files		*sons;

	sons = root->subfiles;
	if (root->subfiles || root->fcount)
		print_dirname(root, opts);
	while (sons)
	{
		st_fputstr(sons->details, root->fields_len);
		sons = (t_files*)sons->next;
	}
	sons = root->subfiles;
	if (!(opts & RECURSIVE))
		return ;
	while (sons)
	{
		if (sons->fcount && !ft_strstr(sons->name, "/..") &&
				ft_strcmp(".", epure_name(sons->name, opts)))
			recurse_out(sons, opts);
		sons = (t_files*)sons->next;
	}
}

void				st_fputstr(char **details, int *nbrmax)
{
	int c;
	int	step;

	c = 0;
	if (!details)
		return ;
	while (details && *details && c <= 7)
	{
		if (*details)
		{
			if (nbrmax)
				step = nbrmax[c] - ft_strlen(*details);
			else
				step = 10;
			c == 3 || c == 2 ? ft_putstr(*details) : 0;
			if (step < 20 && c != 6 && c > 0)
				while (step-- > 0)
					write(1, " ", 1);
			c != 3 && c != 2 ? ft_putstr(*details) : 0;
			ft_putstr(c == 0 || c == 2 || c == 3 ? "  " : " ");
		}
		c++;
		details++;
	}
	ft_putchar('\n');
}
