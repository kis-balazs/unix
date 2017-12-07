/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkis <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/15 16:25:34 by bkis              #+#    #+#             */
/*   Updated: 2017/05/15 16:25:47 by bkis             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	sp_prompt(t_env_item *env, int ret)
{
	char	*prompt;
	char	*home;

	if (ret != 0)
		ft_putnbr(ret);
	if ((prompt = mgetenv(env, "PWD")))
	{
		if ((home = mgetenv(env, "HOME")) && ft_strstr(prompt, home))
		{
			ft_putchar('~');
			ft_putstr(prompt + ft_strlen(home));
		}
		else
			ft_putstr(prompt);
		ft_memdel((void**)&home);
		free(prompt);
	}
	ft_putstr(" ->-> ");
}
