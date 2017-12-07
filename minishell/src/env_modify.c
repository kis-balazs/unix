/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_modify.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkis <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/15 16:24:27 by bkis              #+#    #+#             */
/*   Updated: 2017/05/15 16:24:33 by bkis             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void			env_print(t_env_item *env)
{
	ft_lstiter((t_list*)env, &env_print_node);
}

void			env_print_node(t_list *m)
{
	t_env_item	*n;
	char		*s;

	n = (t_env_item*)m;
	if (!(s = ft_strnew(ft_strlen(n->keyval[0]) + ft_strlen(n->keyval[1]) + 1)))
	{
		ft_putendl_fd("ERROR env_print_node", 2);
		return ;
	}
	ft_strcat(s, n->keyval[0]);
	ft_strcat(s, "=");
	ft_strcat(s, n->keyval[1]);
	if (*s)
		ft_putendl(s);
	free(s);
}

char			*mgetenv(t_env_item *env, char *key)
{
	t_env_item *t;

	t = env;
	while (t && ft_strcmp(t->keyval[0], key))
		t = t->next;
	return (t ? ft_strdup(t->keyval[1]) : NULL);
}

int				msetenv(t_env_item **env, char **keyval, char *pair, int g)
{
	t_env_item *t;
	t_env_item *a;

	if (!pair || setenv_check(pair))
		return (1);
	t = env_new_item(keyval, pair, g);
	if (!*env && (*env = t))
		return (0);
	a = *env;
	while (a->next && ft_strcmp(a->keyval[0], t->keyval[0]))
		a = a->next;
	if (a->next || !ft_strcmp(a->keyval[0], t->keyval[0]))
	{
		free(a->keyval[1]);
		a->keyval[1] = ft_strdup(t->keyval[1]);
		env_del_one(t);
		free(t);
	}
	else
	{
		a->next = t;
		t->prev = a;
	}
	return (0);
}

int				munsetenv(t_env_item **env, char *key)
{
	t_env_item	*a;

	a = *env;
	if (!key)
		return (1);
	if (!ft_strcmp(key, (*env)->keyval[0]))
	{
		if ((*env)->next)
			(*env)->next->prev = NULL;
		*env = (*env)->next;
		ft_strtdel(&a->keyval);
		ft_strdel((char**)&a);
		return (0);
	}
	while (a && ft_strcmp(a->keyval[0], key))
		a = a->next;
	if (!a)
		return (1);
	if (a->prev)
		a->prev->next = a->next;
	if (a->next)
		a->next->prev = a->prev;
	ft_strtdel(&a->keyval);
	ft_strdel((char**)&a);
	return (0);
}
