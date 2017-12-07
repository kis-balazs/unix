/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   access.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkis <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/15 16:21:54 by bkis              #+#    #+#             */
/*   Updated: 2017/05/15 16:22:27 by bkis             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char				*cin_c2c(char *c1, char **c2)
{
	int	c;

	c = 0;
	while (*(c2 + c) && ft_strncmp(c1, *(c2 + c), ft_strlen(c1)))
		c++;
	return (*(c2 + c));
}

static inline char	*cjoin(char *path, char *cmd)
{
	char	*ret;
	int		c;
	int		i;

	c = 0;
	if (!(ret = malloc(ft_strlen(cmd) + 2 +
					(ft_strlen(path) - ft_strlen(ft_strchr(path, ':'))))))
		exit(EXIT_FAILURE);
	while (path[c] && path[c] != ':')
	{
		ret[c] = path[c];
		c++;
	}
	ret[c] = '/';
	c++;
	i = 0;
	while (cmd[i])
	{
		ret[c + i] = cmd[i];
		i++;
	}
	ret[c + i] = 0;
	return (ret);
}

char				*in_path(char *cmd, char *path)
{
	char	*ccm;
	int		c;

	c = 0;
	ccm = NULL;
	while (path && access((ccm = cjoin(path, cmd)), X_OK))
	{
		if ((path = ft_strchr(path, ':')))
		{
			path += 1;
			free(ccm);
		}
		c++;
	}
	if (!path && ccm)
	{
		free(ccm);
		ccm = NULL;
	}
	return (ccm);
}
