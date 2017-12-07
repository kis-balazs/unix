/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkis <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/07 13:20:50 by bkis              #+#    #+#             */
/*   Updated: 2017/07/07 13:20:52 by bkis             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

static void		go_home(char *home_bis)
{
	char		*home;
	char		*pwd;

	pwd = get_pwd();
	if ((home = search_env(g_env, "HOME=")) == NULL)
		ft_putendl_fd("no home set", 2);
	else
	{
		if (home_bis == NULL || !home_bis[1])
		{
			chdir(home);
			replace_env(&g_env, "PWD=", home, &g_memory.env_lenght);
			replace_env(&g_env, "OLDPWD=", pwd, &g_memory.env_lenght);
		}
	}
	free(pwd);
}

static void		cd_pwd(char *save_pwd)
{
	char		*pwd;
	char		*tmp;

	if (!search_env(g_env, "PWD="))
	{
		tmp = get_pwd();
		pwd = ft_strjoin("PWD=", tmp);
		ft_lstadd(&g_env, ft_lstnew(pwd, ft_strlen(pwd)));
		free(pwd);
		free(tmp);
	}
	if (!search_env(g_env, "OLDPWD="))
	{
		tmp = ft_strjoin("OLDPWD=", save_pwd);
		ft_lstadd(&g_env, ft_lstnew(tmp, ft_strlen(tmp)));
		free(tmp);
	}
}

void			dash_one(char *str)
{
	char		*tmp;
	char		*save_pwd;

	save_pwd = get_pwd();
	chdir(str);
	if ((!search_env(g_env, "PWD") || !search_env(g_env, "OLDPWD=")))
		cd_pwd(save_pwd);
	if (search_env(g_env, "OLDPWD="))
		replace_env(&g_env, "OLDPWD=", save_pwd, &g_memory.env_lenght);
	if (search_env(g_env, "PWD="))
	{
		tmp = get_pwd();
		replace_env(&g_env, "PWD=", tmp, &g_memory.env_lenght);
		free(tmp);
	}
	free(save_pwd);
}

void			ft_cd(char **cmd, int index)
{
	if (index == 4)
		ft_putendl_fd("cd: too many arguments", 2);
	if (index == 1)
		go_home(NULL);
	if (index > 1)
	{
		if (*cmd[1] == '-' && search_env(g_env, "OLDPWD="))
			dash_one(search_env(g_env, "OLDPWD="));
		else if (index == 2 && is_dir(cmd[1]) == REP)
			dash_one(cmd[1]);
		else
		{
			ft_putstr_fd("cd: no such file or directory:", 2);
			ft_putendl_fd(cmd[1], 2);
		}
	}
}
