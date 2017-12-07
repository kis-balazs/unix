/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_histfile_path.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkis <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/07 13:26:19 by bkis              #+#    #+#             */
/*   Updated: 2017/07/07 13:26:20 by bkis             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "termcaps.h"

void	get_histfile_path(void)
{
	char	*tmp;
	char	*tmp2;

	if (search_env(g_env, "HOME="))
	{
		tmp = ft_strtrijoin("HISTORY=", search_env(g_env, "HOME="), "/");
		tmp2 = ft_strjoin(tmp, ".my_history");
		ft_lstadd(&g_env, ft_lstnew(tmp2, ft_strlen(tmp2)));
		g_memory.env_lenght++;
		free(tmp);
		free(tmp2);
	}
}
