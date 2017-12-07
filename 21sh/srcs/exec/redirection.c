/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkis <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/07 13:25:03 by bkis              #+#    #+#             */
/*   Updated: 2017/07/07 13:25:04 by bkis             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

static void		ft_machon(char *token, int ret_fd[4], int pcr)
{
	char			*tmp;

	tmp = NULL;
	if (token[pcr] == '&' && token[pcr + 1] == '-')
		ret_fd[3] = open("/dev/null", O_WRONLY, 0666);
	else if (token[pcr] == '&')
	{
		pcr++;
		tmp = ft_strdup(token + pcr);
		ret_fd[2] = ft_atoi(tmp);
		free(tmp);
	}
	else
		ret_fd[3] = -1;
}

void			central2(char *after, t_list_fd *list, char *token, int count)
{
	if (count == 2)
	{
		if (!after)
			ft_machon(token, list->fd, list->pcr + 1);
		else
		{
			list->fd[0] = 1;
			list->fd[2] = open(after, O_WRONLY | O_TRUNC | O_CREAT, 0666);
		}
		return ;
	}
	if (count == 3)
	{
		if (!after)
			ft_machon(token, list->fd, list->pcr + 1);
		else
		{
			list->fd[0] = 0;
			list->fd[2] = open(after, O_RDONLY, 0666);
		}
		return ;
	}
}

void			central(char *after, t_list_fd *list, char *token, int count)
{
	if (count == 0)
	{
		if (!after)
			ft_machon(token, list->fd, list->pcr + 2);
		else
		{
			list->fd[0] = 0;
			list->fd[2] = open(after, O_RDONLY | O_APPEND, 0666);
		}
		return ;
	}
	if (count == 1)
	{
		if (!after)
			ft_machon(token, list->fd, list->pcr + 2);
		else
		{
			list->fd[0] = 1;
			list->fd[2] = open(after, O_WRONLY | O_APPEND | O_CREAT, 0666);
		}
		return ;
	}
	central2(after, list, token, count);
}

static int		rediction_fd(t_list_fd *list, char *token)
{
	char			*tmp;
	int				pcr;

	pcr = 0;
	tmp = NULL;
	while (ft_isdigit(token[pcr]))
		pcr++;
	if (pcr > 0)
	{
		tmp = ft_strndup(token, 0, pcr);
		list->fd[0] = ft_atoi(tmp);
		free(tmp);
	}
	if (token[0] == '&')
	{
		list->fd[1] = 2;
		pcr++;
	}
	return (pcr);
}

void			reacast_fd(char *token, char *after, t_list_fd *list)
{
	const char		*tableau[4];
	int				count;

	count = 0;
	tableau[0] = "<<";
	tableau[1] = ">>";
	tableau[2] = ">";
	tableau[3] = "<";
	list->fd[0] = 0;
	list->fd[1] = 0;
	list->fd[2] = 0;
	list->fd[3] = 0;
	list->pcr = 0;
	list->pcr = rediction_fd(list, token);
	while (count < 5)
	{
		if (!(ft_strncmp(tableau[count], token + list->pcr,
			ft_strlen(tableau[count]))))
		{
			central(after, list, token, count);
			return ;
		}
		count++;
	}
}
