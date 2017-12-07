/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   from_deep_space.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkis <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/07 13:46:25 by bkis              #+#    #+#             */
/*   Updated: 2017/07/07 13:46:25 by bkis             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

bool	from_deep_space(char *str, size_t len)
{
	size_t	count;

	count = 0;
	while (*str)
	{
		if (*str == ' ')
			++count;
		++str;
	}
	return (count == len ? true : false);
}
