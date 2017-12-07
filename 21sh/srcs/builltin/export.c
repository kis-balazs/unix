/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkis <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/07 13:21:27 by bkis              #+#    #+#             */
/*   Updated: 2017/07/07 13:21:28 by bkis             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

static void			saw_varible(void)
{
	t_llist			*ptr;

	ptr = g_memory.variable;
	while (ptr)
	{
		ft_putendl(ptr->content);
		ptr = ptr->next;
	}
}

int					set_varible(t_node *ast, int *status)
{
	char			*sigle;
	char			*name;
	int				count;

	count = 0;
	while (ast->body->lexem->name_lexem[count] != '=')
		count++;
	sigle = ft_strndup(ast->body->lexem->name_lexem, 0, count + 1);
	name = ft_strdup(ast->body->lexem->name_lexem + count + 1);
	if (search_env(g_memory.variable, sigle) == NULL)
	{
		ft_lstadd(&g_memory.variable, ft_lstnew(ast->body->lexem->name_lexem,
					ft_strlen(ast->body->lexem->name_lexem)));
		g_memory.var_lenght++;
	}
	else
		replace_env(&g_memory.variable, sigle, name, &(g_memory).var_lenght);
	free(sigle);
	free(name);
	*status = 0;
	return (1);
}

static void			exp_env(char *str)
{
	t_llist			*ptr;
	t_llist			*save;

	ptr = g_memory.variable;
	while (ptr)
	{
		save = ptr;
		if (!ft_strncmp(ptr->content, str, ft_strlen(str)))
			ft_lstadd(&g_env, ft_lstnew(ptr->content,
						ft_strlen(ptr->content)));
		ptr = ptr->next;
	}
}

static void			export_env(char *str)
{
	char			*sigle;
	char			*name;
	int				count;

	count = 0;
	while (str[count] && str[count] != '=')
		count++;
	if (!str[count])
	{
		exp_env(str);
		return ;
	}
	sigle = ft_strndup(str, 0, count + 1);
	name = ft_strdup(str + count + 1);
	if ((find_varibale(str, '=')) > 0)
	{
		while (str[count] != '=')
			count++;
		ft_lstadd(&g_env, ft_lstnew(str, ft_strlen(str)));
	}
	else if ((search_env(g_env, str)) == NULL)
		replace_env(&g_env, sigle, name, &(g_memory).env_lenght);
	free(sigle);
	free(name);
}

void				ft_export(char *arg)
{
	if (!arg)
		saw_varible();
	else
		export_env(arg);
}
