/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkis <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/07 14:02:37 by bkis              #+#    #+#             */
/*   Updated: 2017/07/07 14:02:38 by bkis             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Includes/libft.h"

size_t		ft_strlen(const char *str)
{
	size_t		index;

	index = 0;
	if (str == NULL)
		return (0);
	while (str[index] != '\0')
		index++;
	return (index);
}
