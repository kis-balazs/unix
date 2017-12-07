/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   access_gestion.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkis <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/07 13:22:28 by bkis              #+#    #+#             */
/*   Updated: 2017/07/07 13:22:29 by bkis             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

int				print_error(char *cmd, t_code code, char **path, int lenght)
{
	if (code == CD_CMD)
		ft_putstr_fd("shell: command not found: ", 2);
	ft_putendl_fd(cmd, 2);
	free_d(path, lenght);
	free(path);
	return (-1);
}

char			*ctrl_access(char **path, char *name)
{
	char		*tmp;
	int			count;

	count = 0;
	tmp = NULL;
	while (path[count])
	{
		tmp = ft_strtrijoin(path[count], "/", name);
		if (access(tmp, X_OK) == 0)
			return (tmp);
		free(tmp);
		count++;
	}
	return (NULL);
}

char			**find_path(int *lenght)
{
	char		**path;
	int			*tableau;

	tableau = generate(':', 0, 3);
	if (!(*lenght = ft_strsplit(&path, search_env(g_env, "PATH="), tableau)))
	{
		free(tableau);
		return (NULL);
	}
	free(tableau);
	return (path);
}

int				find_command(char **cmd)
{
	char		**path;
	int			lenght_path;
	char		*tmp;

	tmp = NULL;
	lenght_path = 0;
	if (access(*cmd, X_OK) == 0)
		return (1);
	if (is_bulltin(*cmd) == 1)
		return (1);
	if ((path = find_path(&lenght_path)) == NULL)
		return (print_error(*cmd, CD_CMD, path, lenght_path));
	if ((tmp = ctrl_access(path, *cmd)) == NULL)
	{
		free(tmp);
		return (print_error(*cmd, CD_CMD, path, lenght_path));
	}
	else
	{
		free(*cmd);
		MACREALLOC(*cmd, tmp, ft_strlen(tmp) + 1);
	}
	free_d(path, lenght_path);
	free(path);
	return (1);
}
