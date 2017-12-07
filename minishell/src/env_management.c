/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_management.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkis <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/15 16:24:14 by bkis              #+#    #+#             */
/*   Updated: 2017/05/15 16:24:20 by bkis             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_env_item		*env_new_item(char **keyval, char *keyval_in_one, int g)
{
	t_env_item	*n;
	int			c;

	n = NULL;
	c = 0;
	if (!(n = malloc(sizeof(t_env_item)))
			|| !(n->keyval = ft_strtnew(2)))
		return (NULL);
	if (keyval_in_one)
	{
		if (!(keyval = ft_strsplit(keyval_in_one, "=")))
			return (NULL);
		c = 1;
	}
	n->keyval[0] = ft_strdup(keyval[0]);
	n->keyval[1] = ft_strdup(keyval[1]);
	n->keyval[2] = NULL;
	n->next = NULL;
	n->prev = NULL;
	n->glob = g;
	if (c)
		ft_strtdel(&keyval);
	return (n);
}

int				env_populate(t_env_item **env, char **environ)
{
	int			c;
	t_env_item	*item;

	c = 0;
	while (environ && environ[c])
	{
		item = env_new_item(NULL, environ[c], 1);
		if (!*env)
			*env = item;
		else
			ft_lstinsert((t_list**)env, (t_list*)item, &env_fake_sort);
		c++;
	}
	return (0);
}

void			env_del_one(void *t)
{
	t_env_item *item;

	item = (t_env_item*)t;
	ft_strtdel(&item->keyval);
}

void			env_free(t_env_item **env)
{
	if (!*env)
		return ;
	ft_lstdel((t_list**)env, &env_del_one);
	if (*env)
	{
		free(*env);
		*env = NULL;
	}
}

char			**env_to_table(t_env_item *env)
{
	char		**new_env;
	t_env_item	*t;
	int			c;

	c = 0;
	if (!(t = env))
		return (NULL);
	while ((t = t->next))
		c++;
	t = env;
	if (!(new_env = ft_strtnew((size_t)(c + 1))))
		return (NULL);
	c = 0;
	while (t)
	{
		new_env[c] = ft_strjoin(t->keyval[0], ft_strjoin("=", t->keyval[1]));
		c++;
		t = t->next;
	}
	return (new_env);
}
