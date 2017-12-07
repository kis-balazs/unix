/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setenv.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkis <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/07 13:21:39 by bkis              #+#    #+#             */
/*   Updated: 2017/07/07 13:21:41 by bkis             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

void			ft_setenv(char *name, char *value)
{
	char		*str;

	str = NULL;
	if (!name || !value)
	{
		ft_putendl_fd("Wrong set of env", 2);
		return ;
	}
	if ((search_env(g_env, name)) != NULL)
	{
		ft_putendl_fd(name, 2);
		ft_putendl_fd("already set", 2);
		return ;
	}
	str = ft_strtrijoin(name, "=", value);
	ft_lstadd(&g_env, ft_lstnew(str, ft_strlen(str)));
	g_memory.env_lenght++;
	free(str);
}

void			ft_unsetenv(char **name)
{
	int			i;

	i = 1;
	while (name[i])
		clear_env(&g_env, name[i++], &g_memory.env_lenght);
}
