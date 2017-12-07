/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdir.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkis <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/07 13:55:18 by bkis              #+#    #+#             */
/*   Updated: 2017/07/07 13:55:19 by bkis             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Includes/libft.h"

int					is_dir(char *s)
{
	struct stat		buf;
	int				i;

	i = 0;
	if (stat(s, &buf) == -1)
		return (-1);
	i = S_ISREG(buf.st_mode) ? 50 : i;
	i = S_ISDIR(buf.st_mode) ? 60 : i;
	i = S_ISLNK(buf.st_mode) ? 70 : i;
	return (i);
}
